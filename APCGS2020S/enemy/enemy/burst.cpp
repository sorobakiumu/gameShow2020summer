#include "burst.h"

void burst::UpDate()
{
	MapPos.x -= 5;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::BURST][animCnt], LAYER::ENEMY, 996));
}

void burst::Draw()
{
}

burst::burst()
{
}

burst::~burst()
{
}
