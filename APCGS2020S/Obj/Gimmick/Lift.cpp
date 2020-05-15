#include <DxLib.h>
#include "Lift.h"
#include "../../scene/SceneManage.h"

Lift::Lift()
{
	Pos = { -100,-100 };
	Size = { 0,0 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::LIFT;
	Speed = {0,0};
	Image = LoadGraph("image/���t�g.png");
	dead = false;
}

Lift::Lift(Vec2double pos, Vec2double StartPos, Vec2double EndPos,int Movetime)
{
	Pos = pos;
	Size = { 0,0 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::LIFT;
	Speed = (StartPos-EndPos)/static_cast<double>(Movetime);	// �n�_�ƏI�_�̍�����1�b������̈ړ��ʂ����߂�
	MovingTime = 0;
	MoveTime = Movetime;
	Image = LoadGraph("image/���t�g.png");
	dead = false;
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
	lpSceneMng.addDrawQue(std::make_tuple(Pos,1.0,0.0,Image,LAYER::MAP,999));
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