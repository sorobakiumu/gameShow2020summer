#include "wolf.h"

void wolf::UpDate()
{
	MapPos.x--;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0,lpEnemy. enemyImage[ENEMY_ID::WOLF][animCnt], LAYER::ENEMY, 999));
}

void wolf::Draw()
{
}

wolf::wolf()
{
	MapPos = {200,200};
}

wolf::~wolf()
{
}
