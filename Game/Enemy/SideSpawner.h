#pragma once
#include "Spawner.h"
class CollisionManager;
class SideSpawner :
	public Spawner
{
private:
	int frame = 0;;
	std::shared_ptr<CollisionManager> cm_;
public:
	SideSpawner(const Position2f& pos, Enemy* prototype, std::shared_ptr<EnemyManager>& em, std::shared_ptr<CollisionManager> col, std::shared_ptr<Camera> c);
	void Update();
};

