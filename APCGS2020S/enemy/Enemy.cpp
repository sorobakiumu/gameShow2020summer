#include "Enemy.h"
#include "../manager/SceneManage.h"
#include "../scene/LAYER.h"
#include "../Obj/Obj.h"
#include "../manager/CheckHitManage.h"
#include <DxLib.h>
#include<math.h>
#include "enemy/baze.h"
#include "enemy/black.h"
#include "enemy/boss.h"
#include "enemy/burst.h"
#include "enemy/ghost.h"
#include "enemy/man.h"
#include "enemy/rare.h"
#include "enemy/wolf.h"

Enemy* Enemy::sInstance = nullptr;

void Enemy::UpDate(Vec2double pPos)
{


	switch (_enemyID)
	{
	case (ENEMY_ID::WOLF):
		_enemylist.emplace_back(new wolf());
		break;
	case (ENEMY_ID::GHOST):
		_enemylist.emplace_back(new ghost());
		break;
	case (ENEMY_ID::MAN):
		_enemylist.emplace_back(new man());
		break;
	case (ENEMY_ID::BLACK):
		_enemylist.emplace_back(new black());
		break;
	case (ENEMY_ID::BURST):
		_enemylist.emplace_back(new burst());
		break;
	case (ENEMY_ID::BAZE):
		_enemylist.emplace_back(new baze());
		break;
	case (ENEMY_ID::BOSS):
		_enemylist.emplace_back(new boss());
		break;
	case (ENEMY_ID::RARE):
		_enemylist.emplace_back(new rare());
		break;
	default:
		break;
	}


	for (auto eQue : _enemylist)
	{
		(*eQue).UpDate(pPos);
	}

	auto itr = std::remove_if(_enemylist.begin(),				// チェックの開始地点
		_enemylist.end(),								// チェックの終了地点
		/* ラムダ式*/  [](sharedEnemy& enemy) {return (*enemy).Dead(); }	// removeの条件
	);

}

Enemy::Enemy()
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
	LoadDivGraph("image/ブラックアンドホワイト.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::BLACK][0]);
	//BURST
	LoadDivGraph("image/自爆マン.bmp", 2, 2, 1, 32, 32, &enemyImage[ENEMY_ID::BURST][0]);
	//BAZE
	LoadDivGraph("image/バゼ.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::BAZE][0]);
	//PIT
	enemyImage[ENEMY_ID::PIT][0] = LoadGraph("image/ピット.bmp");
	//BOSS
	LoadDivGraph("image/ボス.png", 2, 2, 1, 64, 64, &enemyImage[ENEMY_ID::BOSS][0]);
	//RARE
	LoadDivGraph("image/レア.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::RARE][0]);


	_enemyID = ENEMY_ID::BOSS;
}

Enemy::~Enemy()
{
	
}

