#pragma once
#include <memory>
#include <list>
class Enemy;
///<summary>
///敵全体を管理する
///</summary>
class EnemyManager
{
private:
	using Enemies_t =std::list<std::shared_ptr<Enemy>>;
	Enemies_t enemies_;
public:
	void AddEnemy(Enemy* enemy);
	Enemies_t& Enemies();
	void UpDate();
	void Draw();
};

