#pragma once
#include "../../Obj/Obj.h"

struct FuncCheckHit
{
	void operator()(int no,void* scene);
private:
	Vec2double Pos;
	Vec2Int Size;
};

