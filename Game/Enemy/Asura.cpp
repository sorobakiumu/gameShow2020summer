#include "Asura.h"
#include "../../System/FileManager.h"
#include <DxLib.h>
#include <random>
#include "BossShot.h"
#include "../../Scene/GamePlaingScene.h"
#include "../Collision/CircleCollider.h"
#include "../ProjectileManage.h"
#include "../Collision/CollisionManager.h"
#include "../Player/Camera.h"
#include "EnemyManager.h"

namespace {
	const float shotSpeed = 5;
	const float redius = 16;
	float xpos;
}

Enemy* Asura::MakeClone()
{
	return new Asura(this->gameScene);
}

void Asura::InitializeUpdate()
{
	LoadDivGraph(L"image/enemy/asyura/ƒ{ƒX.png", 3, 3, 1, 64, 64, &ashuraH_[0]);
	LoadDivGraph(L"image/enemy/asyura/chargeball.png",30,6,5,100,100,&chargeH_[0]);

	updater_ = &Asura::EnteringUpdate;
	camera_->ViewOffset().x;
	pos_.x = 800 - camera_->ViewOffset().x;
	pos_.y = 400;
	xpos = 700 - camera_->ViewOffset().x;
}

void Asura::EnteringUpdate()
{
	pos_.x-=2;
	if (pos_.x <= xpos) {
		updater_ = &Asura::NormalUpdate;
	}
}

void Asura::NormalUpdate()
{
	if (frame_ % 60 == 59) {
		Attack(enelgyBalls + Vector2f(pos_.x, pos_.y));
	}
	if (pos_.x > 700 - camera_->ViewOffset().x) {
		pos_.x--;
	}
	if (gameScene->GetCollisionManager()->GetBossLife() <= 0) {
		updater_ = &Asura::ExitingUpdate;
	}
	pos_.y += static_cast<double>((((frame_ / 240) % 2) * 2) - 1);
}

void Asura::Attack(Position2f& pos)
{
	Vector2f vel = Vector2f(-shotSpeed, -shotSpeed/2);
	NomerizePush(vel, pos);
	vel = Vector2f(-shotSpeed, 0);
	NomerizePush(vel, pos);
	vel = Vector2f(-shotSpeed, shotSpeed/2);
	NomerizePush(vel, pos);
}

void Asura::NomerizePush(Vector2f& vel, Position2f& pos)
{
	vel.Nomerize();
	gameScene->GetProjectileManage().AddProjectile(new BossShot(pos, vel, camera_));
	gameScene->GetCollisionManager()->AddColliders(new CircleCollider(gameScene->GetProjectileManage().GetProjecties().back(), "eblt", Circle(Vector2f(0,0), redius)));
}



void Asura::DamageUpdate()
{
	if (frame_ % 60 == 59) {
		Attack(enelgyBalls + Vector2f(pos_.x, pos_.y));
	}
	if ((frame_ - cnt) < 15) {
		if (drawer_ == &Asura::DamageDraw) {
			drawer_ = &Asura::NormalDraw;
		}
		else if (drawer_ == &Asura::NormalDraw) {
			drawer_ = &Asura::DamageDraw;
		}
	}
	else if ((frame_ - cnt) >= 15) {
		drawer_ = &Asura::NormalDraw;
		updater_ = &Asura::NormalUpdate;
	}
	pos_.x++;
}

void Asura::ExitingUpdate()
{
	pos_.y += 2;
	if (drawer_ == &Asura::DamageDraw) {
		drawer_ = &Asura::NormalDraw;
	}
	else if (drawer_ == &Asura::NormalDraw) {
		drawer_ = &Asura::DamageDraw;
	}
	if (pos_.y >= 800) {
		updater_ = &Asura::DeadUpdate;
	}
}

void Asura::DeadUpdate()
{
	gameScene->ChangeScene();
}

void Asura::NormalDraw()
{
	DrawRotaGraph2(pos_.x + camera_->ViewOffset().x, pos_.y,32,32,1.5,0.0,ashuraH_[frame_%3],true,false);
	if (frame_ % 60 > 30) {
		DrawRotaGraph(pos_.x + enelgyBalls.x + camera_->ViewOffset().x, pos_.y + enelgyBalls.y, 1.0, 0.0, chargeH_[frame_ % 30], true);
	}
}

void Asura::DamageDraw()
{
	NormalDraw();
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	NormalDraw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Asura::ExitingDraw()
{
}

void Asura::DeadDraw()
{

}

Asura::Asura(GamePlaingScene* gm):Boss(gm)
{
	updater_ = &Asura::InitializeUpdate;
	drawer_ = &Asura::NormalDraw;
}

void Asura::OnHit(CollisionInfo& col, CollisionInfo&)
{
	if (updater_ == &Asura::NormalUpdate) {
		auto& life = gameScene->GetCollisionManager()->GetBossLife();
		life--;
		updater_ = &Asura::DamageUpdate;
		drawer_ = &Asura::DamageDraw;
		cnt = frame_;
	}
}

void Asura::OnDamage(int damage)
{
}

void Asura::OnDead()
{
}

void Asura::Update()
{
	frame_++;
	(this->*updater_)();
}

void Asura::Draw()
{
	(this->*drawer_)();
}
