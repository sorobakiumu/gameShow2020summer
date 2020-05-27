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

