#include "baze.h"

void baze::UpDate()
{
	MapPos.x -= 3;
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 4;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::BAZE][animCnt], LAYER::ENEMY, 996));
}

void baze::Draw()
{
}

baze::baze(double pos)
{
	MapPos.x = pos+lpSceneMng.ScreenSize.x;
	MapPos.y = CHIP_SIZE;
	dead = false;
	alive = true;
	Rad = 0;
	ID = OBJ_ID::FRY_ENEMY;
}

baze::~baze()
{
}
