#include "GunShot.h"
#include <DxLib.h>
#include "../../System/FileManager.h"
#include "../../System/File.h"
#include "Camera.h"

GunShot::GunShot(const Vector2f pos, const Vector2f vel, std::shared_ptr<Camera> camera)
	:Projectile(camera)
{
	Pos = pos;
	vel_ = vel;
	angle = 0;
	bulletH = FileManager::Instance().Load(L"image/player/shot/gunshot.png", "PL_EQUIP")->Handle();
	isActive_ = true;
}

void GunShot::Update()
{
	Pos += vel_;
}

void GunShot::Draw()
{
	float xoffset = camera_->ViewOffset().x;
	DrawRotaGraph(Pos.x+xoffset,Pos.y,2,angle,bulletH,true);
}

void GunShot::OnHit(CollisionInfo&, CollisionInfo&)
{
}

GunShot::~GunShot()
{
}
