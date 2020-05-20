#include "Enemy.h"
#include "../scene/SceneManage.h"
#include "../scene/LAYER.h"
#include <DxLib.h>


bool Enemy::initFlag;

void Enemy::UpDate()
{


	//�����蔻�菈��
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
	enemyImage[ENEMY_ID::WOLF].resize(10);
	enemyImage[ENEMY_ID::GHOST].resize(10);
	enemyImage[ENEMY_ID::MAN].resize(10);
	enemyImage[ENEMY_ID::BLACK].resize(10);
	enemyImage[ENEMY_ID::BURST].resize(10);
	enemyImage[ENEMY_ID::BAZE].resize(10);
	enemyImage[ENEMY_ID::PIT].resize(10);
	enemyImage[ENEMY_ID::BOSS].resize(10);
	enemyImage[ENEMY_ID::RARE].resize(10);


	//WOLF
	LoadDivGraph("image/�E���t.png", 3, 3, 1, 32, 32, &enemyImage[ENEMY_ID::WOLF][0]);
	//GHOST
	LoadDivGraph("image/�S�[�X�g.bmp", 6, 6, 1, 32, 32, &enemyImage[ENEMY_ID::GHOST][0]);
	//MAN
	LoadDivGraph("image/�j.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::MAN][0]);
	//BLACK
	LoadDivGraph("image/�u���b�N�A���h�z���C�g.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::BLACK][0]);
	//BURST
	LoadDivGraph("image/�����}��.bmp", 8, 8, 1, 32, 32, &enemyImage[ENEMY_ID::BURST][0]);
	//BAZE
	LoadDivGraph("image/�o�[.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::BAZE][0]);
	//PIT
	enemyImage[ENEMY_ID::PIT][0] =LoadGraph("image/�s�b�g.bmp");
	//BOSS
	LoadDivGraph("image/�{�X.png", 2, 2, 1, 64, 64, &enemyImage[ENEMY_ID::BOSS][0]);
	//RARE
	LoadDivGraph("image/���A.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::RARE][0]);

	initFlag = false;
}

void Enemy::Draw()
{
}

void Enemy::wolff()
{
	MapPos.x++;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos,1.0,0.0,enemyImage[ENEMY_ID::WOLF][animCnt],LAYER::ENEMY,999));
}

void Enemy::ghost()
{
	MapPos.x++;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 6;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::GHOST][animCnt], LAYER::ENEMY, 999));
}

Enemy::Enemy(ENEMY_ID enemyId)
{
	_enemyID = enemyId;
	MapPos = { 10,10 };
	flag = true;

	frmCnt =lpSceneMng.FrmCnt();

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
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::MAN][animCnt], LAYER::ENEMY, 999));
}

void Enemy::black()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BLACK][animCnt], LAYER::ENEMY, 999));
}

void Enemy::burst()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BURST][animCnt], LAYER::ENEMY, 999));
}

void Enemy::baze()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BAZE][animCnt], LAYER::ENEMY, 999));
}

void Enemy::boss()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BOSS][animCnt], LAYER::ENEMY, 998));
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::PIT][0], LAYER::ENEMY, 999));
}

void Enemy::rare()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::RARE][animCnt], LAYER::ENEMY, 999));
}
