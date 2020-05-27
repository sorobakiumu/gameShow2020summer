#include "black.h"

void black::UpDate()
{
	MapPos.x -= 3;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::BLACK][animCnt], LAYER::ENEMY, 996));
}

void black::Draw()
{
}

black::black(double pos)
{
	MapPos.x = pos + lpSceneMng.ScreenSize.x;
	MapPos.y = rand() % static_cast<int>(lpSceneMng.ScreenCenter.y + lpSceneMng.ScreenCenter.y / 2);
	dead = false;
	alive = true;
	Rad = 0;
}

black::~black()
{
}
