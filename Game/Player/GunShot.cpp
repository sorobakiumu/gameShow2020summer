#include "GunShot.h"
#include <DxLib.h>
#include "../../System/FileManager.h"
#include "../../System/File.h"
#include "Camera.h"
#include "../Collision/Collider.h"

GunShot::GunShot(const Vector2f pos, const Vector2f vel, std::shared_ptr<Camera> camera)
	:Projectile(camera)
{
	pos_ = pos;
	vel_ = vel;
	angle = atan2(vel.y,vel.x);
	bulletH = FileManager::Instance().Load(L"image/player/shot/gunshot.png", "PL_EQUIP")->Handle();
	isActive_ = true;
}

void GunShot::Update()
{
	pos_ += vel_;
	auto Vrange = camera_->GetViewRange();
	if ((pos_.x<Vrange.pos.x || pos_.x>Vrange.pos.x+Vrange.size.w)||
		(pos_.y<Vrange.pos.y || pos_.y>Vrange.pos.y + Vrange.size.h))
	{
		isActive_ = false;
	}
}

void GunShot::Draw()
{
	float xoffset = camera_->ViewOffset().x;
	DrawRotaGraph(pos_.x+xoffset, pos_.y,2,angle,bulletH,true);
}

void GunShot::OnHit(CollisionInfo& other, CollisionInfo& my)
{
	if (other.collider->GetTag() == "edmg")
	{
		isActive_ = false;
	}
}

GunShot::~GunShot()
{
}
