#include "rare.h"

void rare::UpDate()
{
	MapPos.x -= 10;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::RARE][animCnt], LAYER::ENEMY, 996));
}

void rare::Draw()
{
}

rare::rare(double pos)
{
	MapPos.x = pos + lpSceneMng.ScreenSize.x;
	MapPos.y = rand() % static_cast<int>(lpSceneMng.ScreenCenter.y + lpSceneMng.ScreenCenter.y / 2);
	dead = false;
	alive = true;
	Rad = 0;
	ID = OBJ_ID::ENEMY;
}

rare::~rare()
{
}
