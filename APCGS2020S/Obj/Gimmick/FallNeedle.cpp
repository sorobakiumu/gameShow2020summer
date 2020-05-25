#include <DxLib.h>
#include "FallNeedle.h"
#include "../../manager/SceneManage.h"
#include "../../manager/CheckHitManage.h"
#include "../../scene/Func/FuncCheckHit.h"

FallNeedle::FallNeedle()
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::MAX;
	MapPos = {-100,-100};
	Size = {0,0};
	FallFlag = false;
	Image = 0;
	dead = false;
}

FallNeedle::FallNeedle(Vec2double pos)
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::MAX;
	MapPos = pos;
	Size = { 32,32 };
	FallFlag = false;
	Image = LoadGraph("image/FALLTOGE.png");
	dead = false;
}

FallNeedle::~FallNeedle()
{

}

void FallNeedle::UpDate()
{
	if (FallFlag!=true)
	{
		for (int i = -1; i < 2; i++)
		{
			for (int j = 2; j < 7; j++)
			{
				//CheckHit({MapPos.x + 32 * i,MapPos.y + 32 * j},{MapPos.x + 32 * i,MapPos.y + 32 * j});
				FallFlag = true;
			}
		}
	}
	else
	{
		MapPos.y+=5;
		if (/*lpCheckHit.CheckHit(MapPos,Size)||*/MapPos.y>ScrSize.y+64)
		{
			FallFlag = false;
			MapPos.y = 32;
		}
	}
}

void FallNeedle::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image, LAYER::MAP, 999));
}

