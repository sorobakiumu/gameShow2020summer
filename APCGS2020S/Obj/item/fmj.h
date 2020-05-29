#pragma once
#include "../Obj.h"
#include"../item.h"
class fmj :
	public Obj
{
public:
	void UpDate();
	void Draw();
	fmj(Vec2double pos) { MapPos = pos; dead = false;}
};

