#include "FallLift.h"
#include "DxLib.h"
#include "../../scene/SceneManage.h"

FallLift::FallLift()
{
	ID=OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::FALL_LIFT;
	Speed = 0;
	Pos = { 0,0 };
	FallFlag = false;
	Size = { 0,0 };
	Image = LoadGraph("image/リフト.png");
	dead = false;
}

FallLift::FallLift(Vec2double pos, int speed)
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::FALL_LIFT;
	Speed = speed;
	Pos = pos;
	FallFlag = false;
	Size = { 0,0 };
	Image = LoadGraph("image/リフト.png");
	dead = false;
}

FallLift::~FallLift()
{

}

void FallLift::UpDate()
{
	if (FallFlag==true)
	{
		Pos.y += Speed;
	}
	Draw();
}

void FallLift::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, Image,LAYER::MAP,999));
}