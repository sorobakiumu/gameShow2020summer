#pragma once
#include "../../Obj/Obj.h"

struct FuncCheckHit
{
	void operator()(int no,void* scene,Vec2double pos);
private:
	Vec2double Pos;
	Vec2Int Size;
	bool CheckHit[4]; // ����A�E��A�����A�E���̏��œ������Ă��邩�ǂ���
};

