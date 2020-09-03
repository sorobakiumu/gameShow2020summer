#include "Slaher.h"
#include "DxLib.h"
#include "../Player/Player.h"
#include <math.h>
#include "../Collision/CircleCollider.h"
#include "../Effect.h"
#include "../Player/Camera.h"
#include "../Stage.h"

namespace {
	int runH = -1;
	int slashH = -1;
}



Enemy* Slasher::MakeClone()
{
	return new Slasher(*this);
}

void Slasher::RunUpdate()
{

	if (flame % 150 == 0)
	{
		AimPlayer();
		velocity_.x *= 5;
		velocity_.y *= 5;
	}
	pos_ += velocity_;
	animFrame_ = (animFrame_ + 1) % 15;

	auto seg3 = stage_->GetThreeSegment(pos_);
	auto groundy = stage_->ComputeGlandY(pos_);
	if (seg3[1].IsNILL())
	{
		pos_.y = groundy;
	}
	if(groundy -60 < pos_.y)
	{
		pos_.y = groundy-60;
	}

	if (velocity_.x > 0)
	{
		if (seg3[2].IsNILL()) {
			auto diff = seg3[1].End().x - pos_.x;
			if (0 < diff && diff <= fabsf(velocity_.x)) {
				velocity_.y = -15.0f;//ãŒü‚«‘¬“x 
				updater_ = &Slasher::JampUpdate;
			}
		}
	}
	else {
		if (seg3[0].IsNILL()) {
			auto diff = seg3[1].End().x - pos_.x;
			if (0 < diff && diff <= fabsf(velocity_.x)) {
				velocity_.y = -15.0f;//ãŒü‚«‘¬“x 
				updater_ = &Slasher::JampUpdate;
			}
		}
	}


	if (fabsf(pos_.x - player_->GetPosition().x) < 50) {
		updater_ = &Slasher::SlashUpdate;
		drawer_ = &Slasher::SlashDraw;
		flame = 1;
	}
}

void Slasher::SlashUpdate()
{
	animFrame_ = (animFrame_ + 1) % 20;
	if (animFrame_ == 0) {
		flame = 1;
		updater_ = &Slasher::RunUpdate;
		drawer_ = &Slasher::RunDraw;
	}
}

void Slasher::JampUpdate()
{
	velocity_.y += 0.75f;
	pos_ += velocity_;
	auto groundy = stage_->ComputeGlandY(pos_);
	if (groundy-60 < pos_.y) {
		pos_.y = groundy-60;
		updater_ = &Slasher::RunUpdate;
	}
}

void Slasher::RunDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = runH;
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRectRotaGraph(pos_.x + xoffset, pos_.y, (animFrame_ / 5) * 36, 0, 36, 36,5.0f, 0.0f, runH, true);
}

void Slasher::SlashDraw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = runH;
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRectRotaGraph(pos_.x+xoffset, pos_.y, (animFrame_ / 5) * 42, 0, 42, 36,5.0f, 0.0f, slashH, true);
}

Slasher::Slasher(const std::shared_ptr<Player>& p, std::shared_ptr<Camera> camera,std::shared_ptr<Stage> st):Enemy(p, camera),stage_(st)
{
	if (runH == -1)
	{
		runH = LoadGraph(L"image/enemy/slasher/run.png");
	}
	if (slashH == -1)
	{
		slashH = LoadGraph(L"image/enemy/slasher/slash.png");
	}
	animFrame_ = 0;
	updater_ = &Slasher::RunUpdate;
	drawer_ = &Slasher::RunDraw;
}

void Slasher::OnDamage(int damage)
{
}

void Slasher::OnDead()
{
}

void Slasher::Update()
{
	if (!player_->IsTimeStop()) 
	{
		flame++;
		(this->*updater_)();
		auto CRange = camera_->GetViewRange();
		if (pos_.y > CRange.pos.y + (CRange.size.h*3/2))
		{
			isDeletable_ = true;
		}
	}
}

void Slasher::Draw()
{
	(this->*drawer_)();
}

const Vector2f& Slasher::GetPosition() const
{
	return pos_;
}

void Slasher::SetPosition(const Vector2f& vel)
{
	pos_.x = vel.x;
	pos_.y = vel.y;
}


const Vector2f& Slasher::GetVelocity() const
{
	return velocity_;
}

void Slasher::SetVelocity(const Vector2f& vel)
{
}

bool Slasher::IsDead() const
{
	return isDeletable_;
}


bool Slasher::IsDeletable() const
{
	return isDeletable_;
}

void Slasher::OnHit(CollisionInfo& col, CollisionInfo&)
{
	if (col.collider->GetTag() == "patk") {
		auto sign = velocity_.x < 0 ? -1.0f : 1.0f;
		effectManager_->EmitBlow(pos_+Vector2f(sign*50,50));
		isDeletable_ = true;
	}
}
