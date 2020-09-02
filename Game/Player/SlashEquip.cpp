#include "SlashEquip.h"
#include "Player.h"
#include "../../System/Input.h"
#include "../ProjectileManage.h"
#include "../Collision/CollisionManager.h"
#include "Camera.h"
#include "../Collision/CircleCollider.h"
#include "../../Scene/GamePlaingScene.h"

namespace {
	const float shotSpeed = 30;
	const float redius = 32;
}

SlashEquip::SlashEquip(ProjectileManage& pm, std::shared_ptr<CollisionManager>& cm, std::shared_ptr<Camera> camera):pm_(pm), Equipment(cm, camera)
{
}

void SlashEquip::Attack(Player& player, const Input& input, Vector2f offset)
{
	Vector2f vel;
	if (player.GetDir() == DIR::LEFT)
	{
		vel= Vector2f(-shotSpeed, 0);
	}
	else
	{
		vel = Vector2f(shotSpeed, 0);
	}

	if (input.IsPressed("left")) {
		vel = Vector2f(-shotSpeed, 0);
	}
	collisionManager_->AddColliders(new CircleCollider(player.GetGameScene()->GetPlayer(),"patk", Circle(Position2f(vel), redius)));
}

void SlashEquip::DoubleAttack(Player& player, const Input& input)
{
}

void SlashEquip::NomerizePush(Vector2f& vel, Player& player)
{
}
