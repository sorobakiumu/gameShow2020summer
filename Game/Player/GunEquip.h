#pragma once
#include "Equipment.h"
#include<memory>

class ProjectileManage;
class CollisionManager;
class Camera;

class GunEquip :
	public Equipment
{
private:
	ProjectileManage& pm_;

	int ShotSpeed = 0;
	float rad = 0;
public:
	GunEquip(ProjectileManage& pm, std::shared_ptr<CollisionManager>& cm, std::shared_ptr<Camera> camera);
	void Attack(Player& player, const Input& input, Vector2f offset)override;
};

