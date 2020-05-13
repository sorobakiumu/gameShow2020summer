#pragma once
#include "Gimmick.h"
class Lift :
	public Gimmick
{
	Lift();
	Lift(Vec2double pos, Vec2double StartPos, Vec2double EndPos,int Movetime);
	~Lift();

private:
	int MoveTime;

	Vec2double Speed;
	int MovingTime;

	void UpDate();
	void Draw();
	void Move();

};
