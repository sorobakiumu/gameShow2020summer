#include "boss.h"

void boss::UpDate()
{
	MapPos.x += static_cast<double>((((lpSceneMng.FrmCnt() / 60) % 2) * 2) - 1);
	int animCnt = (lpSceneMng.FrmCnt() / 30) % 2;
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0,lpEnemy.enemyImage[ENEMY_ID::BOSS][animCnt], LAYER::ENEMY, 998));

	for (int x = 0; x < 4; x++)
	{
		if (pitCnt[x].x == 0.0)
		{
			pitCnt[x].x = 1.0;
		}
		else
		{
			pit(x);

			//“–‚½‚è”»’èŽ®
			lpSceneMng.addDrawQue(std::make_tuple(pitCnt[x], 1.0, 0.0, lpEnemy.enemyImage[ENEMY_ID::PIT][0], LAYER::ENEMY, 999));
		}
	}

}

void boss::Draw()
{
}

boss::boss()
{
	for (int x = 0; x < 4; x++)
	{
		pitCnt[x] = { 0.0,0.0 };
	}

}

boss::~boss()
{
}

void boss::pit(int num)
{
	int animCnt = ((lpSceneMng.FrmCnt())) % 375 + 90 * num;
	pitCnt[num].x = 64 * sin(animCnt * 3.1415 * 180) + MapPos.x;
	pitCnt[num].y = 64 * cos(animCnt * 3.1415 * 180) + MapPos.y;
}
