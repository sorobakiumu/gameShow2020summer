#include "Enemy.h"
#include "../manager/SceneManage.h"
#include "../scene/LAYER.h"
#include "../Obj/Obj.h"
#include "../manager/CheckHitManage.h"
#include <DxLib.h>
#include<math.h>


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
	LoadDivGraph("image/ブラックアンドホワイト.png", 6, 3, 2, 32, 32, &enemyImage[ENEMY_ID::BLACK][0]);
	//BURST
	LoadDivGraph("image/自爆マン.bmp", 2, 2, 1, 32, 32, &enemyImage[ENEMY_ID::BURST][0]);
	//BAZE
	LoadDivGraph("image/バゼ.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::BAZE][0]);
	//PIT
	enemyImage[ENEMY_ID::PIT][0] =LoadGraph("image/ピット.bmp");
	//BOSS
	LoadDivGraph("image/ボス.png", 2, 2, 1, 64, 64, &enemyImage[ENEMY_ID::BOSS][0]);
	//RARE
	LoadDivGraph("image/レア.bmp", 4, 4, 1, 32, 32, &enemyImage[ENEMY_ID::RARE][0]);

	initFlag = false;
}

void Enemy::Draw()
{
}

void Enemy::wolff()
{
	MapPos.x--;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos,1.0,0.0,enemyImage[ENEMY_ID::WOLF][animCnt],LAYER::ENEMY,999));
}

void Enemy::ghost()
{
	MapPos.x--;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 6;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::GHOST][animCnt], LAYER::ENEMY, 999));
}

Enemy::Enemy(ENEMY_ID enemyId)
{
	_enemyID = enemyId;
	MapPos = {1800,200 };
	flag = true;

	frmCnt =lpSceneMng.FrmCnt();

	for (int x = 0; x < 4; x++)
	{
		pitCnt[x] = {0.0,0.0};
	}

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
	


	MapPos.x--;				
	animCnt = (lpSceneMng.FrmCnt() / 30) % 1;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::MAN][animCnt], LAYER::ENEMY, 996));
}

void Enemy::black()
{
	animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BLACK][animCnt], LAYER::ENEMY, 999));
}

void Enemy::burst()
{
	MapPos.x -= 5;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BURST][animCnt], LAYER::ENEMY, 999));
}

void Enemy::baze()
{
	MapPos.x -= 3;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BAZE][animCnt], LAYER::ENEMY, 999));
}

void Enemy::boss()
{
	MapPos.x+=static_cast<double>((((lpSceneMng.FrmCnt() / 60) % 2)*2)-1);
	animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::BOSS][animCnt], LAYER::ENEMY, 998));

	for (int x = 0; x < 4; x++)
	{
		if (pitCnt[x].x == 0.0)
		{
			pitCnt[x].x = 1.0;
		}
		else
		{
			pit(x);

			//当たり判定式
			lpSceneMng.addDrawQue(std::make_tuple(pitCnt[x], 1.0, 0.0, enemyImage[ENEMY_ID::PIT][0], LAYER::ENEMY, 999));
		}
	}


}

void Enemy::rare()
{
	MapPos.x -= 10;
	animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, enemyImage[ENEMY_ID::RARE][animCnt], LAYER::ENEMY, 999));
}

void Enemy::pit(int num)
{	
	animCnt=((lpSceneMng.FrmCnt())) % 375 + 90 * num;
	pitCnt[num].x = 64 * sin(animCnt*3.1415*180) + MapPos.x;
	pitCnt[num].y = 64 * cos(animCnt*3.1415*180) + MapPos.y;
}
