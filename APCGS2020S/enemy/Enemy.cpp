#include "Enemy.h"
#include "../scene/SceneManage.h"

void Enemy::UpDate()
{
	switch (_enemyID)
	{
	case (ENEMY_ID::WOLF):
		wolff();
		break;
	case (ENEMY_ID::GHOST):
		ghost();
		break;
	case (ENEMY_ID::MAN):
		man();
		break;
	case (ENEMY_ID::BLACK):
		black();
		break;
	case (ENEMY_ID::BURST):
		burst();
		break;
	case (ENEMY_ID::BAZE):
		baze();
		break;
	case (ENEMY_ID::BOSS):
		boss();
		break;
	case (ENEMY_ID::RARE):
		rare();
		break;
	default:
		break;
	}


	//delete this;
}

void Enemy::wolff()
{
}

void Enemy::ghost()
{
}

Enemy::Enemy(ENEMY_ID enemyId)
{
	_enemyID = enemyId;

	Pos = { 10,10 };

}

Enemy::~Enemy()
{
}

void Enemy::man()
{
}

void Enemy::black()
{
}

void Enemy::burst()
{
}

void Enemy::baze()
{
}

void Enemy::pit()
{
}

void Enemy::boss()
{
}

void Enemy::rare()
{
}
