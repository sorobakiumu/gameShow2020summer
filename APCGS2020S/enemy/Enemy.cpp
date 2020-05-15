#include "Enemy.h"
#include "../scene/SceneManage.h"
#include"../scene/LAYER.h"

void Enemy::UpDate()
{


	//ìñÇΩÇËîªíËèàóù
	//{
	//delete this;
	//}
	//else
//	{
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
//	}

}

void Enemy::wolff()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos,1.0,0.0,enemyImage[ENEMY_ID::WOLF][0],LAYER::CHAR,999));
}

void Enemy::ghost()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::GHOST][0], LAYER::CHAR, 999));
}

Enemy::Enemy(ENEMY_ID enemyId)
{
	_enemyID = enemyId;

	pos = { 10,10 };
	flag = true;
}

Enemy::~Enemy()
{
	
}

void Enemy::man()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::MAN][0], LAYER::CHAR, 999));
}

void Enemy::black()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BLACK][0], LAYER::CHAR, 999));
}

void Enemy::burst()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BURST][0], LAYER::CHAR, 999));
}

void Enemy::baze()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BAZE][0], LAYER::CHAR, 999));
}

void Enemy::boss()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BOSS][0], LAYER::CHAR, 999));
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::PIT][0], LAYER::CHAR, 999));
}

void Enemy::rare()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::RARE][0], LAYER::CHAR, 999));
}
