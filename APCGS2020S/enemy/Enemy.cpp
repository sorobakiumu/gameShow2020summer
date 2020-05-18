#include "Enemy.h"
#include "../scene/SceneManage.h"
#include "../scene/LAYER.h"
#include <DxLib.h>


bool Enemy::initFlag;

void Enemy::UpDate()
{


	//当たり判定処理
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

void Enemy::EnemyInit()
{
	//WOLF
	LoadDivGraph("ウルフ.png", 3, 3, 1, 32, 32, &enemyImage[ENEMY_ID::WOLF][0]);
	//GHOST
	LoadDivGraph("ゴースト.bmp", 6, 6, 1, 32, 32, &enemyImage[ENEMY_ID::GHOST][0]);
	//MAN
	LoadDivGraph("男.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::MAN][0]);
	//BLACK
	LoadDivGraph("ブラックアンドホワイト.png", 6, 6, 1, 32, 32, &enemyImage[ENEMY_ID::BLACK][0]);
	//BURST
	LoadDivGraph("爆弾.bmp", 8, 8, 1, 32, 32, &enemyImage[ENEMY_ID::BURST][0]);
	//BAZE
	LoadDivGraph("バゼ.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::BAZE][0]);
	//PIT
	enemyImage[ENEMY_ID::PIT][0] =LoadGraph("ピット.bmp");
	//BOSS
	LoadDivGraph("ボス.png", 3, 3, 1, 64, 64, &enemyImage[ENEMY_ID::BOSS][0]);
	//RARE
	LoadDivGraph("レア.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::RARE][0]);
}

void Enemy::wolff()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos,1.0,0.0,enemyImage[ENEMY_ID::WOLF][0],LAYER::CHARA,999));
}

void Enemy::ghost()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::GHOST][0], LAYER::CHARA, 999));
}

Enemy::Enemy(ENEMY_ID enemyId)
{
	_enemyID = enemyId;
	pos = { 10,10 };
	flag = true;

	if (initFlag)
	{
		EnemyInit();
	}
}

Enemy::~Enemy()
{
	
}

void Enemy::man()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::MAN][0], LAYER::CHARA, 999));
}

void Enemy::black()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BLACK][0], LAYER::CHARA, 999));
}

void Enemy::burst()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BURST][0], LAYER::CHARA, 999));
}

void Enemy::baze()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BAZE][0], LAYER::CHARA, 999));
}

void Enemy::boss()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::BOSS][0], LAYER::CHARA, 999));
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::PIT][0], LAYER::CHARA, 999));
}

void Enemy::rare()
{
	lpSceneMng.addDrawQue(std::make_tuple(pos, 1.0, 0.0, enemyImage[ENEMY_ID::RARE][0], LAYER::CHARA, 999));
}
