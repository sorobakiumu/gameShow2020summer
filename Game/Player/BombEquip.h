#pragma once
#include "Equipment.h"
#include<memory>
class ProjectileManage;
class CollisionManager;
class Camera;
class BombEquip :
	public Equipment
{
public:
	BombEquip(ProjectileManage& pm, std::shared_ptr<CollisionManager>& cm, std::shared_ptr<Camera> camera);
	void Attack(Player& player , const Input& input, Vector2f offset)override;
	void DoubleAttack(Player& player, const Input& input)override;
private:
	ProjectileManage& pm_;
	void NomerizePush(Vector2f& vel, Player& player);
};

