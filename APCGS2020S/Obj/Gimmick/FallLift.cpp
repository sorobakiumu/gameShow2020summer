#include "FallLift.h"
#include "DxLib.h"
#include "../../manager/SceneManage.h"

FallLift::FallLift()
{
	ID=OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::FALL_LIFT;
	Speed = 0;
	MapPos = { 0,0 };
	FallFlag = false;
	Size = { 0,0 };
	Image = LoadGraph("image/リフト.png");
	dead = false;
	AnyFlag = false;
}

FallLift::FallLift(Vec2double pos, int speed)
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::FALL_LIFT;
	Speed = speed;
	MapPos = pos;
	FallFlag = false;
	Size = { 96,16 };
	Image = LoadGraph("image/リフト.png");
	dead = false;
	AnyFlag = false;
}

FallLift::~FallLift()
{

}

void FallLift::UpDate()
{
	if (FallFlag==true)
	{
		MapPos.y += Speed;
	}

}

void FallLift::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image,LAYER::MAP,999));
}