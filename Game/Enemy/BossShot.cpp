#include "BossShot.h"
#include <DxLib.h>
#include "../Player/Camera.h"
#include <math.h>


void BossShot::Update()
{
	Projectile::Update();
	if (pos_.x < - camera_->ViewOffset().x || pos_.x>800 - camera_->ViewOffset().x || pos_.y < 0 || pos_.y>600)
	{
		isActive_ = false;
	}
	
}

void BossShot::Draw()
{
	auto gH = shotH[0];
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	angle = atan2(vel_.y,vel_.x);
	auto x = camera_->ViewOffset().x;
	DrawRotaGraph(static_cast<int>(pos_.x + camera_->ViewOffset().x),pos_.y, 1.0f, angle, shotH[frame_%5], true);
}

void BossShot::OnHit(CollisionInfo&, CollisionInfo&)
{
	isActive_ = false;
}

BossShot::BossShot(const Vector2f pos, const Vector2f vel, std::shared_ptr<Camera> camera):Projectile(camera)
{
	pos_ = pos;
	vel_ = vel;
	isActive_ = true;
	angle = 0.0;
	frame_ = 0;
	LoadDivGraph(L"image/enemy/asyura/fireball_b.png",5,5,1,64,32,&shotH[0],true);
}
