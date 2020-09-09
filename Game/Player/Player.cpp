#include "Player.h"
#include "../../Geometry.h"
#include"DxLib.h"
#include<algorithm>
#include <sstream>
#include <iomanip>
#include"../../System/Input.h"
#include"../../Scene/GamePlaingScene.h"
#include "GunEquip.h"
#include "Camera.h"
#include "../Stage.h"
#include"../../System/FileManager.h"
#include "../../System/File.h"
#include"../Collision/CollisionManager.h"
#include "../Collision/CircleCollider.h"
#include "../Effect.h"
#include "SlashEquip.h"

using namespace std;

namespace {
	int frmCnt;
	const Size pl_size = { 32, 32 };
}

void Player::EquipNext()
{
	crrentEquipmentNo_ = (crrentEquipmentNo_ + 1) % em_.size();
#ifdef _DEBUG
	OutputDebugStringA("\nShot Change\n");
#endif // _DEBUG
}

void Player::NormalDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = run_[frmCnt / 5 % 6];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),
		3.0, 0.0, run_[frmCnt / 5 % 6], true, dir == DIR::LEFT);
	AddMovehistry(run_[frmCnt / 5 % 6]);
}

void Player::JampDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = run_[frmCnt / 5 % 6];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),3.0, 0.0, jamp[frmCnt / 5 % 4], true, dir == DIR::LEFT);
	AddMovehistry(jamp[frmCnt / 5 % 4]);
}

void Player::DoubleJampDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = wjamp[frmCnt / 5 % 4];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),3.0, 0.0,wjamp[frmCnt / 5 % 4], true, dir == DIR::LEFT);
	AddMovehistry(wjamp[frmCnt / 5 % 4]);
}

void Player::FallDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = run_[frmCnt / 5 % 6];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),3.0, 0.0, fall[frmCnt / 5 % 2], true,dir==DIR::LEFT);
	AddMovehistry(fall[frmCnt / 5 % 2]);
}

void Player::SetPosition(const Vector2f p)
{
	pos_ = p;
}

Vector2f Player::GetPosition()
{
	return pos_; 
}

void Player::Update()
{
	soundCount++;

	frmCnt++;
	lastPos = pos_;

	em_[crrentEquipmentNo_]->Update();
	(this->*updater_)();




	if (timeStop) {
		if (frmCnt - cnt > 130) {
			PlaySoundMem(espEnd, DX_PLAYTYPE_BACK, TRUE);
		}
		if (frmCnt - cnt > 180) {
			timeStop = false;
			timeinterval = true;
			cnt=frmCnt;
			PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE);
			soundCount = 0;
		}
	}
	if (timeinterval) {
		if (frmCnt - cnt > 300) {
			timeinterval = false;
			gs_->GetEffectMng()->CollPlayerCharge(this, gs_->GetCamera());
			cnt = frmCnt;
			movehistory_.fill({Position2f(0,-100), 0, 0});

		}
	}
	auto CRange = camera_->GetViewRange();
	if (pos_.y > + CRange.pos.y + CRange.size.h*3/2 )
	{
		Death();
	}
}

void Player::Draw()
{
	if (!movehistory_.empty()) {
		for (auto a : movehistory_) {
			ShadowDraw(a);
		}
	}
	(this->*Drawer_)();
	em_[crrentEquipmentNo_]->Draw();
	DrawFormatString(0,100,0xffffff,L"���C�t��%d",playerLife_);
}

void Player::ShadowDraw(std::tuple<Position2f, int, bool> a)
{
	if (timeStop) {

		Position2f pos;
		int gf;
		bool leftflag;
		std::tie(pos,gf,leftflag) = a;
		float xoffset = camera_->ViewOffset().x;
		auto gH = gf;
		int w, h;
		DxLib::GetGraphSize(gH, &w, &h);
		DxLib::CreateMaskScreen();
		DrawFillMask(pos.x + xoffset - 32, pos.y - 32 - h, pos.x + xoffset + 32, pos.y + 32 - h, shadowMask);
		DrawRotaGraph(static_cast<int>(pos.x + xoffset), static_cast<int>(pos.y),3.0, 0.0, gf, true, leftflag);
		DxLib::DeleteMaskScreen();
	}
}

void Player::Move(const Vector2f v,Input input)
{
	auto va = v;
	if (pl_size.w > pos_.x+ camera_->ViewOffset().x + va.x || 800 + pl_size.w < pos_.x+ pl_size.w*2 + camera_->ViewOffset().x + va.x)return;
	pos_ += va;
}

void Player::Attack(const Input& input)
{
	auto offset = Vector2f(0, 0);
	em_[crrentEquipmentNo_]->Attack(*this,input, offset);
}

void Player::AddMovehistry(int gf)
{
	if (timeStop) {
		if (lastPos != pos_) {
			movehistory_[currentMoveIndex_] = { pos_, gf, dir == DIR::LEFT };
			currentMoveIndex_ = (currentMoveIndex_ + 1) % movehistory_.size();
		}
	}
}

DIR Player::GetDir()
{
	return dir;
}

GamePlaingScene* Player::GetGameScene()
{
	return gs_;
}

bool Player::IsTimeStop()
{
	return timeStop;
}

void Player::TimeStopMove()
{
	StopSoundMem(sound);
	soundCount = 0;
	PlaySoundMem(espStart, DX_PLAYTYPE_BACK, TRUE);

	timeStop = true;
	cnt = frmCnt;
}

void Player::DoubleAttack(const Input& input)
{
	em_[crrentEquipmentNo_]->DoubleAttack(*this, input);

}

int Player::GetCrrentEquipmentNo_()const
{
	return crrentEquipmentNo_;
}

void Player::OnHit(CollisionInfo& anathar, CollisionInfo& me)
{
	if (updater_ == &Player::DamageUpdate && (Drawer_ == &Player::DoubleJampDraw && updater_ == &Player::RiseUpdate))
	{
		return;
	}
	if (me.collider->GetTag() == "patk")
	{
		return;
	}
	updater_ = &Player::DamageUpdate;
	knockbackFrame_ = 6;
	playerLife_--;
}

void Player::Jamp()
{
	if (jampCnt >= 2)
	{
		return;
	}
	accelY_ = 1.3f;//���~�����x 
	velY_ = -23.0f;//��������x 
	updater_ = &Player::RiseUpdate;
	Drawer_ = &Player::JampDraw;
	if (jampCnt++ > 0)
	{
		Drawer_ = &Player::DoubleJampDraw;
	}
}

void Player::RiseUpdate()
{
	velY_ += accelY_;
	pos_.y += velY_;


	if (velY_ >= 0.0f) {//�ō��_�ɂȂ����� 
		updater_ = &Player::FallUpdate;
		if (Drawer_ != &Player::DoubleJampDraw)
		{
			Drawer_ = &Player::FallDraw;
		}
	}
}

void Player::FallUpdate()
{
	velY_ += accelY_;
	pos_.y += velY_;
	auto grandy = gs_->GetStage()->ComputeGlandY(pos_);
	if (grandy-55 < pos_.y) { 
		velY_ = 0.0f;
		pos_.y = grandy-55;
		updater_ = &Player::NormalUpdate;
		Drawer_ = &Player::NormalDraw;
		jampCnt = 0;
	}

}

void Player::NormalUpdate()
{
	auto grandy = gs_->GetStage()->ComputeGlandY(pos_);
	if (grandy-55 < pos_.y) {
		pos_.y = grandy-55;
	}
	if (grandy-55 > pos_.y) {
		accelY_ = 1.65f;//���~�����x 
		velY_ = 1.65f;//��������x 
		updater_ = &Player::FallUpdate;
		Drawer_ = &Player::FallDraw;
	}
}

void Player::DamageUpdate()
{
	if (knockbackFrame_-- < 0)
	{
		updater_ = &Player::NormalUpdate;
	}
}

void Player::Initialize()
{


	frmCnt = 0;
	collisionManager_ = gs_->GetCollisionManager();



	gs_->GetEffectMng()->CollPlayerCharge(this, gs_->GetCamera());
	shadowMask = LoadMask(L"image/player/shadow_mask.bmp");

	dir = DIR::RIGHT;
	sound = LoadSoundMem(L"sound/GameScene.mp3");
	espStart = LoadSoundMem(L"sound/espStart.mp3");
	espEnd = LoadSoundMem(L"sound/espEnd.mp3");

	PlaySoundMem(sound, DX_PLAYTYPE_LOOP, FALSE);

	for (int i = 0; i < _countof(run_); ++i) {
		wstringstream wss;
		wss << L"image/player/ran/adventurer-run-";
		wss << setw(2) << setfill(L'0') << i;
		wss << ".png";
		run_[i] = FileManager::Instance().Load(wss.str().c_str(), "PL")->Handle();
	}
	for (int i = 0; i < _countof(jamp); ++i) {
		wstringstream wss;
		wss << L"image/player/jamp/adventurer-jump-";
		wss << setw(2) << setfill(L'0') << i;
		wss << ".png";
		jamp[i] = FileManager::Instance().Load(wss.str().c_str(), "PL")->Handle();
	}
	for (int i = 0; i < _countof(wjamp); ++i) {
		wstringstream wss;
		wss << L"image/player/jamp/adventurer-smrslt-";
		wss << setw(2) << setfill(L'0') << i;
		wss << ".png";
		wjamp[i] = FileManager::Instance().Load(wss.str().c_str(), "PL")->Handle();
	}
	for (int i = 0; i < _countof(fall); ++i) {
		wstringstream wss;
		wss << L"image/player/fall/adventurer-fall-";
		wss << setw(2) << setfill(L'0') << i;
		wss << ".png";
		fall[i] = FileManager::Instance().Load(wss.str().c_str(), "PL")->Handle();
	}
	gs_->AddListener(inputListener_.get());
	em_.emplace_back(make_shared<GunEquip>(gs_->GetProjectileManage(), collisionManager_, camera_));
	em_.emplace_back(make_shared<SlashEquip>(gs_->GetProjectileManage(), collisionManager_, camera_));

	updater_ = &Player::NormalUpdate;
	Drawer_ = &Player::NormalDraw;
}

void Player::Death()
{
	SetPosition(Vector2f(400, 500));
}

Player::Player(GamePlaingScene* gs, std::shared_ptr<Camera> camera):Character(camera)
{
	class PlayerInputListener :public InputLitener {
	private:
		Player& player_;
		bool decizeGravity_=false;
	public:
		PlayerInputListener (Player& p) :player_(p) {};
		void Notify(const Input& input)override {
			if (player_.updater_ == &Player::DamageUpdate) {
				return;
			}
			if (input.IsPressed("left")) {
				player_.Move(Vector2f(-5, 0),input);
				player_.dir = DIR::LEFT;
			}
			if (input.IsPressed("right")) {
				player_.Move(Vector2f(5, 0),input);
				player_.dir = DIR::RIGHT;
			}
			if (input.IsTriggerd("chenge")) {
				if (!player_.IsTimeStop()) {
					if (!player_.timeinterval) {
						player_.TimeStopMove();
					}
				}
				//player_.EquipNext();
			}
			if (input.IsTriggerd("shot")) {
				if (player_.Drawer_ == &Player::DoubleJampDraw)
				{
					player_.DoubleAttack(input);
				}
				else {
					player_.Attack(input);
				}
			}
			if (input.IsTriggerd("jump")) {
				if (player_.jampCnt<2)
				{
					player_.Jamp();
					decizeGravity_ = false;
				}
			}
			if (input.IsReleased("jump")) {
				if (player_.updater_ == &Player::RiseUpdate&&!decizeGravity_)
				{
					player_.accelY_ = max(-player_.velY_/ 10,1.0f);
					decizeGravity_ = true;
				}
			}
		}
	};
	gs_ = gs;
	inputListener_ = std::make_unique<PlayerInputListener>(*this);
	Initialize();
}

Player::~Player()
{
	for (auto& run : run_) {
		DeleteGraph(run);
	}
}
