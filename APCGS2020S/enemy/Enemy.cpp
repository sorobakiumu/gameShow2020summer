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
#include "../scene/GameScene.h"

Enemy* Enemy::sInstance = nullptr;
//
//Enemy::UpDate(Vec2double pPos)
//{ 
//
//
//	switch (_enemyID)
//	{
//	case (ENEMY_ID::WOLF):
//		return wolf();
//		break;
//	case (ENEMY_ID::GHOST):
//		return ghost();
//		break;
//	case (ENEMY_ID::MAN):
//		return man());
//		break;
//	case (ENEMY_ID::BLACK):
//		_enemylist.emplace_back(new black());
//		break;
//	case (ENEMY_ID::BURST):
//		_enemylist.emplace_back(new burst());
//		break;
//	case (ENEMY_ID::BAZE):
//		_enemylist.emplace_back(new baze());
//		break;
//	case (ENEMY_ID::BOSS):
//		_enemylist.emplace_back(new boss());
//		break;
//	case (ENEMY_ID::RARE):
//		_enemylist.emplace_back(new rare());
//		break;
//	default:
//		break;
//	}
//
//
//	for (auto eQue : _enemylist)
//	{
//		(*eQue).UpDate(pPos);
//	}
//
//}

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
	LoadDivGraph("image/�E���t.png", 3, 3, 1, 32, 32, &enemyImage[ENEMY_ID::WOLF][0]);
	//GHOST
	LoadDivGraph("image/�S�[�X�g.bmp", 6, 6, 1, 32, 32, &enemyImage[ENEMY_ID::GHOST][0]);
	//MAN
	LoadDivGraph("image/�j.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::MAN][0]);
	//BLACK
	LoadDivGraph("image/�u���b�N�A���h�z���C�g.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::BLACK][0]);
	//BURST
	LoadDivGraph("image/�����}��.bmp", 2, 2, 1, 32, 32, &enemyImage[ENEMY_ID::BURST][0]);
	//BAZE
	LoadDivGraph("image/�o�[.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::BAZE][0]);
	//PIT
	enemyImage[ENEMY_ID::PIT][0] = LoadGraph("image/�s�b�g.bmp");
	//BOSS
	LoadDivGraph("image/�{�X.png", 2, 2, 1, 64, 64, &enemyImage[ENEMY_ID::BOSS][0]);
	//RARE
	LoadDivGraph("image/���A.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::RARE][0]);


	_enemyID = ENEMY_ID::BOSS;
}

Enemy::~Enemy()
{
	
}

