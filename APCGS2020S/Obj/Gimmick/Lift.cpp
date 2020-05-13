#include "Lift.h"

Lift::Lift()
{
	Pos = { -100,-100 };
	Size = { 0,0 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::LIFT;
	Speed = {0,0};
}

Lift::Lift(Vec2double pos, Vec2double StartPos, Vec2double EndPos,int Movetime)
{
	Pos = pos;
	Size = { 0,0 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::LIFT;
	Speed = (StartPos-EndPos)/static_cast<double>(Movetime);	// 始点と終点の差から1秒当たりの移動量を求める
	MovingTime = 0;
}

Lift::~Lift()
{

}

void Lift::UpDate()
{
	Move();
	Draw();
}

void Lift::Draw()
{

}

void Lift::Move()
{
	Pos += Speed;
	MovingTime++;
	if (MovingTime>=MoveTime)
	{
		MovingTime = 0;
		Speed *= -1;
	}
}