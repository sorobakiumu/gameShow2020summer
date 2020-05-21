#pragma once
#include "../../Obj/Obj.h"

struct FuncCheckHit
{
	bool operator()(Vec2double pos,Vec2double size);
private:
	Vec2double plPos;
	Vec2Int plSize;
};

