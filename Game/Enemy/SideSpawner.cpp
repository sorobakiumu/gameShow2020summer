#include "SideSpawner.h"
#include "Enemy.h"
#include"EnemyManager.h"
#include"../Collision/CollisionManager.h"
#include "../Collision/CircleCollider.h"
#include"../Player/Camera.h"

SideSpawner::SideSpawner(const Position2f& pos, Enemy* prototype, std::shared_ptr<EnemyManager>& em,std::shared_ptr<CollisionManager> col, std::shared_ptr<Camera> c):Spawner(pos,prototype,em,c),cm_(col)
{
}

void SideSpawner::Update()
{
	if (++frame % 60 == 0) {
		auto xoffset = camera_->GetPosition().x;
		auto clone = CreatCloan();
		clone->SetPosition({ -436+xoffset,500 });
		if (rand() % 2 == 0)
		{
			clone->SetPosition({ 436+xoffset,500 });
		}
		enemyManager->AddEnemy(clone);
		cm_->AddColliders(new CircleCollider(enemyManager->Enemies().back(), "edmg", Circle(Vector2f(0, 0), 32.0)));
	}
}
