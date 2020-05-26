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

black::black()
{
}

black::~black()
{
}
