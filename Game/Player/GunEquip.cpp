#include "GunEquip.h"
#include "../ProjectileManage.h"
#include "../../System/Input.h"
#include "GunShot.h"
#include "Player.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/CircleCollider.h"
#include "Camera.h"

GunEquip::GunEquip(ProjectileManage& pm, std::shared_ptr<CollisionManager>& cm, std::shared_ptr<Camera> camera)
	:Equipment(cm,camera),pm_(pm)
{
	ShotSpeed = 20;
	rad = 50;
}

void GunEquip::Attack(Player& player, const Input& input, Vector2f offset)
{
	Vector2f vel = {};
	if (input.IsPressed("up")) {
		vel += Vector2f(0, -ShotSpeed);
	}
	if (input.IsPressed("down")) {
		vel += Vector2f(0,  ShotSpeed);
	}
	if (player.GetDir() == DIR::LEFT)
	{
		if (vel.y==0)
		{
			vel += Vector2f(-ShotSpeed, 0);
		}
	}
	else if (player.GetDir() == DIR::RIGHT)
	{
		if (vel.y == 0)
		{
			vel += Vector2f(ShotSpeed, 0);
		}
	}
	Vector2f test = player.GetPosition();
	pm_.AddProjectile(new GunShot(test,vel,camera_));
	collisionManager_->AddColliders(new CircleCollider(pm_.GetProjecties().back(),
		"patk", Circle(Vector2f(0, 0), rad)));
}
