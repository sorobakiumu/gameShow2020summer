#pragma once
#include "../../Obj/Obj.h"

struct FuncCheckHit
{
	bool operator()(int no,void* scene);
private:
	Vec2double plPos;
	Vec2double ObjPos;
	Vec2Int plSize;
	Vec2Int ObjSize;
};

