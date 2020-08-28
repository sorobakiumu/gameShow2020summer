#include "BossSpawner.h"
#include "EnemyManager.h"
#include"EnemyManager.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/CircleCollider.h"
#include "../Player/Camera.h"
#include "Enemy.h"

void BossSpawner::SpawnUpdate()
{
	auto rc = camera_->GetViewRange();
	if (rc.pos.x + rc.size.w > pos_.x&& rc.pos.x < pos_.x) {
		auto clone = CreatCloan();
		enemyManager->AddEnemy(clone);
		updater_ = &BossSpawner::SleepUpdate;
		collisionManager_->AddColliders(new CircleCollider(enemyManager->Enemies().back(), "bdmg", Circle(Vector2f(0, 0), 32.0)));
	}
}

void BossSpawner::SleepUpdate()
{
	//‰½‚à‚µ‚È‚¢
}

BossSpawner::BossSpawner(Position2f& pos, Enemy* as, std::shared_ptr<EnemyManager>& em, std::shared_ptr<CollisionManager> cm, std::shared_ptr<Camera> c):Spawner(pos,as, em, c),collisionManager_(cm)
{
	updater_ = &BossSpawner::SpawnUpdate;
}

void BossSpawner::Update()
{

	(this->*updater_)();
}
