#include <DxLib.h>
#include "FallNeedle.h"
#include "../../manager/SceneManage.h"

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
	Image = LoadGraph("");
	dead = false;
}

FallNeedle::~FallNeedle()
{

}

void FallNeedle::UpDate()
{
	
}

void FallNeedle::Draw()
{
	
}

