#include <DxLib.h>
#include "Lift.h"
#include "../../manager/SceneManage.h"

Lift::Lift()
{
	MapPos = { -100,-100 };
	Size = { 0,0 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::LIFT;
	Speed = {0,0};
	Image = LoadGraph("image/リフト.png");
	dead = false;
	AnyFlag = false;
}

Lift::Lift(Vec2double pos, Vec2double StartPos, Vec2double EndPos,int Movetime)
{
	MapPos = pos;
	Size = { 96,16 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::LIFT;
	Speed = (StartPos-EndPos)/static_cast<double>(Movetime);	// 始点と終点の差から1秒当たりの移動量を求める
	MovingTime = 0;
	MoveTime = Movetime;
	Image = LoadGraph("image/リフト.png");
	dead = false;
	AnyFlag = false;
}

Lift::~Lift()
{

}

void Lift::UpDate()
{
	Move();
}

void Lift::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos,1.0,0.0,Image,LAYER::MAP,999));
}

void Lift::Move()
{
	MapPos += Speed;
	MovingTime++;
	if (MovingTime>=MoveTime)
	{
		MovingTime = 0;
		Speed *= -1;
	}
}