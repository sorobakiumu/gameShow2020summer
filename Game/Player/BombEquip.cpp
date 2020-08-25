#include "BombEquip.h"
#include "../ProjectileManage.h"
#include "../../System/Input.h"
#include "BombShot.h"
#include "Player.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/CircleCollider.h"
#include "Camera.h"

namespace {
	const float shotSpeed = 10;
	const float redius = 32;
}

BombEquip::BombEquip(ProjectileManage& pm, std::shared_ptr<CollisionManager>& c, std::shared_ptr<Camera> camera):pm_(pm),Equipment(c, camera)
{

}

void BombEquip::Attack(Player& player, const Input& input, Vector2f offset)
{
	Vector2f vel;
	vel = Vector2f(((!player.left * 2.0) - 1.0) * 10, 0.0);
	if (input.IsPressed("up")) {
		vel=Vector2f(0, -shotSpeed);
	}
	if (input.IsPressed("down")) {
		vel = Vector2f(0, shotSpeed);
	}
	if (input.IsPressed("left")) {
		vel = Vector2f(-shotSpeed, 0);
	}
	pm_.AddProjectile(new BombShot(player.GetPosition(), vel,camera_));
	collisionManager_->AddColliders(new CircleCollider(pm_.GetProjecties().back(),
		"patk",Circle(Vector2f(0,0), redius)));
}

void BombEquip::DoubleAttack(Player& player, const Input& input)
{
	Vector2f vel=Vector2f(0, shotSpeed);
	NomerizePush(vel, player);
	vel = Vector2f(-shotSpeed/2, shotSpeed);
	NomerizePush(vel, player);
	vel = Vector2f(shotSpeed/2, shotSpeed);
	NomerizePush(vel, player);
}

void BombEquip::NomerizePush(Vector2f& vel, Player& player)
{
	vel.Nomerize();
	vel.x = vel.x * 1.5;
	vel.y = vel.y * 1.5;
	pm_.AddProjectile(new BombShot(player.GetPosition(), vel, camera_));
	Equipment::collisionManager_->AddColliders(new CircleCollider(pm_.GetProjecties().back(), "patk", Circle(Vector2f(0, 0), redius)));
}