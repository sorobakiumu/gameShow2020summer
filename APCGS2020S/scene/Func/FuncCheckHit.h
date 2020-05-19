#pragma once
#include "../../Obj/Obj.h"

struct FuncCheckHit
{
	void operator()(int no,void* scene,Vec2double pos);
private:
	Vec2double MapPos;
	Vec2Int Size;
};

