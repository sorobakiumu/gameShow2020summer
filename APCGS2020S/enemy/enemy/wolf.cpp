#include "wolf.h"

void wolf::UpDate(Vec2double pPos)
{
	_pos.x--;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 3;
	lpSceneMng.addDrawQue(std::make_tuple(_pos, 1.0, 0.0,lpEnemy. enemyImage[ENEMY_ID::WOLF][animCnt], LAYER::ENEMY, 999));
}

void wolf::Draw()
{
}

wolf::wolf()
{
}

wolf::~wolf()
{
}
