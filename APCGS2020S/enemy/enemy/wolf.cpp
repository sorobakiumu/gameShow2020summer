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

wolf::wolf(double pos)
{
	MapPos.x = pos + lpSceneMng.ScreenSize.x;
	MapPos.y = rand()%static_cast<int>(lpSceneMng.ScreenCenter.y+lpSceneMng.ScreenCenter.y/2);
	dead = false;
	alive = true;
	Rad = 0;
	ID = OBJ_ID::ENEMY;
}

wolf::~wolf()
{
}
