#include "ghost.h"

void ghost::UpDate(Vec2double pPos)
{
	_pos.x--;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 6;
	lpSceneMng.addDrawQue(std::make_tuple(_pos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::GHOST][animCnt], LAYER::ENEMY, 996));
}

void ghost::Draw()
{
}

ghost::ghost()
{
}

ghost::~ghost()
{
}
