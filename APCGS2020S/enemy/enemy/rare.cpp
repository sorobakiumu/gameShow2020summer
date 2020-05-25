#include "rare.h"

void rare::UpDate(Vec2double pPos)
{
	_pos.x -= 10;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(_pos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::RARE][animCnt], LAYER::ENEMY, 996));
}

void rare::Draw()
{
}

rare::rare()
{
}

rare::~rare()
{
}
