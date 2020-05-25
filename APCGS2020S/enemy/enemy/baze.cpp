#include "baze.h"

void baze::UpDate(Vec2double pPos)
{
	_pos.x -= 3;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(_pos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::BAZE][animCnt], LAYER::ENEMY, 996));
}

void baze::Draw()
{
}

baze::baze()
{
}

baze::~baze()
{
}
