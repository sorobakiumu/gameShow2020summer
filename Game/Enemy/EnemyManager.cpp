#include "EnemyManager.h"
#include "Enemy.h"
#include <algorithm>

void EnemyManager::AddEnemy(Enemy* enemy)
{
	EnemyManager::enemies_.emplace_back(enemy);
}

std::list<std::shared_ptr<Enemy>>& EnemyManager::Enemies()
{
	return enemies_;
}

void EnemyManager::UpDate()
{
	for (auto& e : enemies_) {
		e->Update();
	}
	auto it = remove_if(enemies_.begin(), enemies_.end(), [this](std::shared_ptr<Enemy>& e)
		{
			return e->IsDeletable();
		});
	enemies_.erase(it, enemies_.end());
}

void EnemyManager::Draw()
{
	for (auto& e : enemies_) {
		e->Draw();
	}
}
