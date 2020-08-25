#include <DxLib.h>
#include "Stage.h"
#include <assert.h>
#include "Player/Camera.h"
#include "../System/Debugger.h"
#include <algorithm>
#include <array>
#include "../System/FileManager.h"
#include "../System/File.h"
#include "../Scene/GamePlaingScene.h"
#include "../Game/Enemy/Asura.h"
#include "../Game/Enemy/BossSpawner.h"

namespace {
	int stageAtlasH_ = -1;
	constexpr float block_scale = 2.0f;
	constexpr int ground_line = 600;
	constexpr uint8_t  layer_back0 = 0;
	constexpr uint8_t  layer_back1 = 1;
	constexpr uint8_t  layer_back_front = 2;
	constexpr uint8_t  layer_back_collision = 3;
	constexpr uint8_t  layer_back_enemy = 4;
	constexpr uint8_t  boss_no = 255;
}

void Stage::CreateSegment(Position2f& lastPos,Position2f& pos)
{
	if (lastPos.IsNILL())
	{
		terrainSegment_.push_back(Segment::NIL);
	}
	else {
		terrainSegment_.emplace_back(lastPos, pos - lastPos);
	}
	lastPos = pos;
}

void Stage::NormalUpdate()
{
	CheckBossMode();
	if (isBossMode_) {
		gamescene_->AddSpawner(new BossSpawner(Position2f(0, 0),new Asura(gamescene_),gamescene_->GetEnemyManager(),gamescene_->GetCollisionManager(),camera_));
		updater_ = &Stage::BossUpdate;
	}
}

void Stage::BossUpdate()
{
}

std::array<Segment, 3> Stage::GetThreeSegment(const Position2f& pos) const
{
	std::array<Segment, 3> ret = { Segment::NIL,Segment::NIL ,Segment::NIL };
	auto it = find_if(terrainSegment_.begin(), terrainSegment_.end(), [pos](const Segment& seg) {
			const auto& spos = seg.start;
			auto epos= seg.vec;
			epos.x += spos.x;
			epos.y += spos.y;
			return spos.x <= pos.x && pos.x <= epos.x;
		});
		if (it == terrainSegment_.end()) {
			return ret;
		}
		ret[1] = *it;
		if (it != terrainSegment_.begin()) {
			ret[0] = *prev(it);
		}
		if (next(it) != terrainSegment_.end()) {
			ret[2] = *next(it);
		}
		return ret;
}

void Stage::Load(const TCHAR* path, std::shared_ptr<Camera> camera)
{




	camera_ = camera;
	auto h = DxLib::FileRead_open(path);
	assert(h > 0);
	DxLib::FileRead_read(&stageHeader_, sizeof(stageHeader_),h);
	stagedata_.resize(stageHeader_.layer);
	auto layerSize = stageHeader_.mapH * stageHeader_.mapW;
	for (int i = 0; i < stageHeader_.layer; i++) {
		stagedata_[i].resize(layerSize);
		DxLib::FileRead_read(stagedata_[i].data(), layerSize, h);
	}

	DxLib::FileRead_close(h);
	auto stagedata = stagedata_;
	for (int d = 0; d < stageHeader_.layer; ++d) {
		for (size_t y = 0; y < stageHeader_.mapH; ++y) {
			for (size_t x = 0; x < stageHeader_.mapW; ++x) {
				stagedata_[d][y + x * stageHeader_.mapH] =stagedata[d][x + y * stageHeader_.mapW];
			}
		}
	}

	constexpr uint8_t tr_point = 1;//線分を構築する点(左上始点)
	constexpr uint8_t tr_end = 2;//線分を構築する点(右上終点)
	constexpr uint8_t tr_point_end = 3;//線分を構築する点(左上始点右下終点)
	constexpr uint8_t tr_change_point = 4;
	const auto collisionLayerNo = layer_back_collision;
	Position2f lastPos = Position2f::NIL;
	Position2f PendingPos = Position2f::NIL;
	terrainSegment_.clear();
	auto yoffset = ground_line - stageHeader_.mapH * stageHeader_.chipH * block_scale;
	for (unsigned int x = 0; x < stageHeader_.mapW; ++x) {
		for (unsigned int y = 0; y < stageHeader_.mapH; ++y) {
			auto data = stagedata_[collisionLayerNo][y + x * stageHeader_.mapH];
			if (data == 0)continue;
			auto pos = Position2f((float)x * stageHeader_.chipW, (float)y * stageHeader_.chipH) * block_scale + Vector2f(0, yoffset);
			switch (data)
			{
			case tr_point:
				if (PendingPos.IsNILL())
					{
						CreateSegment(lastPos, pos);
					}
					else {
						CreateSegment(lastPos, pos);
						CreateSegment(pos, PendingPos);
						lastPos = PendingPos;
						PendingPos = Position2f::NIL;
					}
				break;
			case tr_end:
				pos += Position2f(stageHeader_.chipW * block_scale, 0);
				CreateSegment(lastPos, pos);
				lastPos = Position2f::NIL;
				break;
			case tr_point_end:
				CreateSegment(lastPos, pos);
				pos += Position2f(stageHeader_.chipW * block_scale, stageHeader_.chipH * block_scale);
				CreateSegment(lastPos, pos);
				lastPos = Position2f::NIL;
				break;
			case tr_change_point:
				PendingPos = pos;
				break;
			default:
				break;
			}
		}
	}
}

float Stage::ComputeGlandY(const Position2f& pos)const {
	auto it = find_if(terrainSegment_.begin(), terrainSegment_.end(), [pos](const Segment& seg) {
		auto spos = seg.start;
		auto epos = spos + seg.vec;
		return spos.x <= pos.x && pos.x <= epos.x;});
	if (it == terrainSegment_.end()) {
		return FLT_MAX;
	}
	float a = it->vec.y / it->vec.x;
	return it->start.y + a * (pos.x - it->start.x);
}

Vector2f Stage::ComputeOverlapWall(const Position2f& pos,float f) const
{
	auto it = find_if(terrainSegment_.begin(), terrainSegment_.end(), [this,pos](const Segment& seg) {
		if (seg.vec.IsNILL())return false;
		if (seg.vec.x > 0.0f)return false;
		auto v = pos;
		v -=seg.start;
		//垂線の長さ
		auto vren = fabs(v.Clas(seg.vec.Nomerized()));
		//射影の長さ
		auto sren = v.Dot(seg.vec.Nomerized());
		if (sren > seg.vec.Magnitude()||sren<0)return false;
		return true;
		});
	if (it == terrainSegment_.end()) {
		return Vector2f(0, 0);
	}
	auto v = pos-it->start;
	auto vv = it->vec * v.Dot(it->vec) / it->vec.SQMagnitude();
	auto n = v - vv;
	auto mag = n.Magnitude();
	if (mag == 0.0f)return Vector2f(0, 0);
	return n.Nomerized()*(f-mag);
}

void Stage::CheckBossMode()
{
	constexpr uint8_t boss_no = 255;
	auto rc = camera_->GetViewRange();
	size_t xleft = static_cast<size_t>(static_cast<float>(rc.pos.x) /
		(stageHeader_.chipW * block_scale));
	size_t xright = static_cast<size_t>(static_cast<float>(rc.pos.x+rc.size.w) /
		(stageHeader_.chipW * block_scale));
	auto itBegin = stagedata_[layer_back_enemy].begin();

	isBossMode_ = std::count(
		std::next(itBegin, xleft * stageHeader_.mapH),//first 
		std::next(itBegin, xright * stageHeader_.mapH),//last 
		boss_no) > 0;
}

bool Stage::IsBossMode() const
{
	return isBossMode_;
	/*auto viewrange = camera_->GetViewRange();
	int xleft = viewrange.pos.x / (stageHeader_.chipW * block_scale);
	int xright = (viewrange.pos.x+viewrange.size.w) / (stageHeader_.chipW * block_scale);
	
	auto itBegin = stagedata_[layer_back_enemy].begin();
	auto a= std::count(std::next(itBegin, xleft * stageHeader_.mapH), std::next(itBegin, xleft * stageHeader_.mapH), boss_no);
	return std::count(std::next(itBegin, xleft * stageHeader_.mapH), std::next(itBegin, xright * stageHeader_.mapH), boss_no);*/
}

void Stage::Update()
{
	(this->*updater_)();
}

void Stage::Draw()
{
	auto xoffset = camera_->ViewOffset().x;
	constexpr float scale=2.0f;
	constexpr float gland_line = 600.0f;
	const float yofSet = gland_line-(stageHeader_.chipH*scale*stageHeader_.mapH);
	auto rc = camera_->GetViewRange();
	for (int d = 0; d < stageHeader_.layer-2; d++) {
		for (unsigned int x = 0; x < stageHeader_.mapW; ++x) {
			float xpos = x * stageHeader_.chipW * 2.0f;
			float xmargin = stageHeader_.chipW * 2.0f;
		if (xpos < rc.pos.x-xmargin|| rc.pos.x + rc.size.w  < xpos) {
			continue;
		}
			for (unsigned int y = 0; y < stageHeader_.mapH; ++y) {
				auto chip = stagedata_[d][y + x * stageHeader_.mapH];
				DxLib::DrawRectRotaGraph2(
					static_cast<int>(x * stageHeader_.chipW* scale+xoffset), static_cast<int>(yofSet+ y * stageHeader_.chipH* scale),
					(chip % 16) * stageHeader_.chipW, (chip / 16) * stageHeader_.chipW,
					stageHeader_.chipW, stageHeader_.chipW,
					0,0,
					scale,0.0f,stageAtlasH_, true);
			}
		}
	}

	if (Debugger::Instance().IsDebugMode())
	{
		for (auto& seg : terrainSegment_) {
			auto spos = seg.start+Position2f(xoffset,0);
			auto epos = spos + seg.vec;
			DrawLine((int)spos.x, (int)spos.y,
				(int)epos.x, (int)epos.y,
				0xffffff, 3);
		}
	}
}

Stage::Stage(std::shared_ptr<Camera> camera, GamePlaingScene* gs):camera_(camera),gamescene_(gs)
{
	stageAtlasH_ = LoadGraph(L"image/BG/level/level_atlas.png");
	updater_ = &Stage::NormalUpdate;
}
