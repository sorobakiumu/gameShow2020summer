#pragma once
#include <memory>
#include <list>
#include <string>

class Collider;
class CollisionManager
{
private:
	std::list <std::shared_ptr<Collider>> colliders_;
	int bossLife_ = 30;
	void TagCheck(std::shared_ptr<Collider>& colA, std::shared_ptr<Collider>& colB, int& retflag, std::string tag);

public:
	void FalseImmortal();
	int& GetBossLife();
	void AddColliders(Collider*);
	void Update();
	void DebagDraw();
};

