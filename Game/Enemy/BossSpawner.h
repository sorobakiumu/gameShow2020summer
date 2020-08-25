#pragma once
#include "Spawner.h"
#include "../Collision/CollisionManager.h"

class Asura;
class BossSpawner :
	public Spawner
{
private:
	std::shared_ptr<CollisionManager> collisionManager_;

	void SpawnUpdate();

	void SleepUpdate();
public:
	BossSpawner(Position2f&, Enemy*, std::shared_ptr<EnemyManager>&, std::shared_ptr<CollisionManager>, std::shared_ptr<Camera>);
	using UpdateFunction_t = void (BossSpawner::*)();
	UpdateFunction_t updater_;
	void Update();
};

