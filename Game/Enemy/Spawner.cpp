#include "Spawner.h"
#include "Enemy.h"
#include "EnemyManager.h"

Enemy* Spawner::CreatCloan()
{
	return prototype_->MakeClone();
}

Spawner::Spawner(const Position2f& pos, Enemy* prototype, std::shared_ptr<EnemyManager>& em, std::shared_ptr<Camera> c): pos_(pos), prototype_(prototype), enemyManager(em),camera_(c)
{

}
