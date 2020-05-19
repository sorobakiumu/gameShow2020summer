#include "Enemy.h"
#include "../scene/SceneManage.h"
#include "../scene/LAYER.h"
#include <DxLib.h>"


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
	LoadDivGraph("image/ウルフ.png", 3, 3, 1, 32, 32, &enemyImage[ENEMY_ID::WOLF][0]);
	//GHOST
	LoadDivGraph("image/ゴースト.bmp", 6, 6, 1, 32, 32, &enemyImage[ENEMY_ID::GHOST][0]);
	//MAN
	LoadDivGraph("image/男.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::MAN][0]);
	//BLACK
	LoadDivGraph("image/ブラックアンドホワイト.png", 6, 6, 1, 32, 32, &enemyImage[ENEMY_ID::BLACK][0]);
	//BURST
	LoadDivGraph("image/爆弾.bmp", 8, 8, 1, 32, 32, &enemyImage[ENEMY_ID::BURST][0]);
	//BAZE
	LoadDivGraph("image/バゼ.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::BAZE][0]);
	//PIT
	enemyImage[ENEMY_ID::PIT][0] =LoadGraph("image/ピット.bmp");
	//BOSS
	LoadDivGraph("image/ボス.png", 3, 3, 1, 64, 64, &enemyImage[ENEMY_ID::BOSS][0]);
	//RARE
	LoadDivGraph("image/レア.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::RARE][0]);

	initFlag = false;
}

void Enemy::Draw()
{
}

void Enemy::wolff()
{
	Pos.x++;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(Pos,1.0,0.0,enemyImage[ENEMY_ID::WOLF][animCnt],LAYER::CHARA,999));
}

void Enemy::ghost()
{
	Pos.x++;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 6;
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::GHOST][animCnt], LAYER::CHARA, 999));
}

Enemy::Enemy(ENEMY_ID enemyId)
{
	_enemyID = enemyId;
	Pos = { 10,10 };
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
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::MAN][animCnt], LAYER::CHARA, 999));
}

void Enemy::black()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::BLACK][animCnt], LAYER::CHARA, 999));
}

void Enemy::burst()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::BURST][animCnt], LAYER::CHARA, 999));
}

void Enemy::baze()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::BAZE][animCnt], LAYER::CHARA, 999));
}

void Enemy::boss()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::BOSS][animCnt], LAYER::CHARA, 998));
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::PIT][0], LAYER::CHARA, 999));
}

void Enemy::rare()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, enemyImage[ENEMY_ID::RARE][animCnt], LAYER::CHARA, 999));
}
