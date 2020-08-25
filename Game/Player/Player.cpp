#include "Player.h"
#include "../../Geometry.h"
#include"DxLib.h"
#include<algorithm>
#include <sstream>
#include <iomanip>
#include"../../System/Input.h"
#include"../../Scene/GamePlaingScene.h"
#include "BombEquip.h"
#include "Camera.h"
#include "../Stage.h"
#include"../../System/FileManager.h"
#include "../../System/File.h"
#include"../Collision/CollisionManager.h"
#include "../Collision/CircleCollider.h"

using namespace std;

namespace {
	int frmCnt;
	const Size pl_size = { 32, 32 };
}

void Player::NormalDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = run_[frmCnt / 5 % 6];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph2(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),
		w/2,h-1,
		3.0, 0.0, run_[frmCnt / 5 % 6], true, left);
}

void Player::JampDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = run_[frmCnt / 5 % 6];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph2(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),
		w / 2, h - 1,
		3.0, 0.0, jamp[frmCnt / 5 % 4], true, left);
}

void Player::DoubleJampDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = wjamp[frmCnt / 5 % 4];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph2(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y), 
		w / 2, h - 1, 
		3.0, 0.0,wjamp[frmCnt / 5 % 4], true, left);
}

void Player::FallDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = run_[frmCnt / 5 % 6];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph2(static_cast<int>(pos_.x + xoffset), static_cast<int>(pos_.y),
		w/2,h-1,
		3.0, 0.0, fall[frmCnt / 5 % 2], true, left);
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
	frmCnt++;

	em_[crrentEquipmentNo_]->Update();
	(this->*updater_)();
}

void Player::Draw()
{

	(this->*Drawer_)();
	em_[crrentEquipmentNo_]->Draw();
	DrawFormatString(0,100,0xffffff,L"ライフ＝%d",playerLife_);
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

void Player::DoubleAttack(const Input& input)
{
	em_[crrentEquipmentNo_]->DoubleAttack(*this, input);

}

int Player::CrrentEquipmentNo_()const
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
	accelY_ = 1.3f;//下降加速度 
	velY_ = -23.0f;//上向き速度 
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


	if (velY_ >= 0.0f) {//最高点になったら 
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
	if (grandy < pos_.y) { 
		velY_ = 0.0f;
		pos_.y = grandy;
		updater_ = &Player::NormalUpdate;
		Drawer_ = &Player::NormalDraw;
		jampCnt = 0;
	}

}

void Player::NormalUpdate()
{
	auto grandy = gs_->GetStage()->ComputeGlandY(pos_);
	if (grandy < pos_.y) {
		pos_.y = grandy;
	}
	if (grandy > pos_.y) {
		accelY_ = 1.65f;//下降加速度 
		velY_ = 1.65f;//上向き速度 
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

Player::Player(GamePlaingScene* gs, std::shared_ptr<Camera> camera):Character(camera)
{
	for (int i = 0; i < _countof(run_); ++i) {
		wstringstream wss;
		wss << L"image/player/ran/adventurer-run-";
		wss << setw(2) << setfill(L'0') << i;
		wss << ".png";
		//run_[i] = LoadGraph(wss.str().c_str());
		run_[i] = FileManager::Instance().Load(wss.str().c_str(),"PL")->Handle();
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
	frmCnt = 0;
	updater_ = &Player::NormalUpdate;
	Drawer_ = &Player::NormalDraw;

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
				player_.left = true;
			}
			if (input.IsPressed("right")) {
				player_.Move(Vector2f(5, 0),input);
				player_.left = false;
			}
			if (input.IsTriggerd("chenge")) {
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
	collisionManager_ = gs->GetCollisionManager();
	inputListener_ = std::make_unique<PlayerInputListener>(*this);
	gs->AddListener(inputListener_.get());
	em_.emplace_back(make_shared<BombEquip>(gs->GetProjectileManage(), collisionManager_,camera_));
	gs_ = gs;
}

Player::~Player()
{
	for (auto& run : run_) {
		DeleteGraph(run);
	}
}
