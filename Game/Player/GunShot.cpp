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
	angle = 0;
	bulletH = FileManager::Instance().Load(L"image/player/shot/gunshot.png", "PL_EQUIP")->Handle();
	isActive_ = true;
}

void GunShot::Update()
{
	pos_ += vel_;
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
