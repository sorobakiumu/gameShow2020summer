#pragma once
#include "../Obj.h"
#include"../item.h"
class bannsoukou :
	public Obj
{
public:
	void UpDate();
	void Draw();
	bannsoukou(Vec2double pos) { MapPos = pos; dead = false;}
};

