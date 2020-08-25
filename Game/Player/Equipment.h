#pragma once
#include "../../Geometry.h"
#include <memory>
class Player;
class Input;
class CollisionManager;
class Camera;
class Equipment
{
protected:
	std::shared_ptr<CollisionManager> collisionManager_;
	std::shared_ptr<Camera> camera_;
public:
	Equipment(std::shared_ptr<CollisionManager> c, std::shared_ptr<Camera> camera);
	Equipment();
	virtual void Attack(Player& player, const Input& input, Vector2f offset) {}
	virtual void DoubleAttack(Player& player, const Input& input) {}
	virtual void Update() {}
	virtual void Draw() {}
};

