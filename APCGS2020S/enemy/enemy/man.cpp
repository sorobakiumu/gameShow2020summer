#include "man.h"
#include "../Enemy.h"

void man::UpDate()
{
	MapPos.x--;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 1;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0,lpEnemy.enemyImage[ENEMY_ID::MAN][animCnt], LAYER::ENEMY, 996));
}

void man::Draw()
{
}

man::man()
{
}

man::~man()
{
}
