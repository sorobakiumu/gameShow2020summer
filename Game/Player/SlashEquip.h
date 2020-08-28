#pragma once
#include "Equipment.h"
#include<memory>
class ProjectileManage;
class CollisionManager;
class Camera;
class SlashEquip :
	public Equipment
{
public:
	SlashEquip(ProjectileManage& pm, std::shared_ptr<CollisionManager>& cm, std::shared_ptr<Camera> camera);
	void Attack(Player& player, const Input& input, Vector2f offset)override;
	void DoubleAttack(Player& player, const Input& input)override;
	virtual void Update() {}
	virtual void Draw() {}
private:
	ProjectileManage& pm_;
	void NomerizePush(Vector2f& vel, Player& player);
};
