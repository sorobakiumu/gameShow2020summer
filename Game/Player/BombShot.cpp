#include "BombShot.h"
#include "../Projectile.h"
#include "DxLib.h"
#include "../Collision/Collider.h"
#include "Camera.h"
#include "../../System/FileManager.h"
#include"../../System/File.h"

namespace {
	int shot;
}


BombShot::BombShot(const Vector2f pos, const Vector2f vel, std::shared_ptr<Camera> camera):Projectile(camera)
{
	pos_ = pos;
	vel_ = vel;
	shot = FileManager::Instance().Load(L"image/player/shot/bombshot.png", "PL_EQUIP")->Handle(); 
	isActive_ = true;
	angle = 0.0;
}



void BombShot::Update()
{
	Projectile::Update();
	angle +=  DX_PI_F / 6.0;
	auto xoffset = camera_->GetPosition().x;
	if (pos_.x < xoffset-400 || pos_.x>xoffset +400 || pos_.y < 0 || pos_.y>600)
	{
		isActive_ = false;
	}
}

void BombShot::Draw()
{
	float xoffset = camera_->ViewOffset().x;
	auto gH = shot;
	int w, h;
	DxLib::GetGraphSize(gH, &w, &h);
	DrawRotaGraph(pos_.x+xoffset,pos_.y-h,1.0f,angle,shot,true);
}

void BombShot::OnHit(CollisionInfo& col, CollisionInfo&)
{
	if (col.collider->GetTag() == "edmg") {
		isActive_ = false;
	}
	
}

Position2f BombShot::Pos()
{
	auto pos = pos_;
	pos.x -= camera_->ViewOffset().x;
	return pos;
}

Position2 BombShot::Size()
{
	return { 32,32 };
}

BombShot::~BombShot()
{
#ifdef _DEBUG
	OutputDebugStringA("\nBomb Shot is delete\n");
#endif // _DEBUG

}