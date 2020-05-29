#pragma once
#include "../Obj.h"
#include"../item.h"
class gaze :
	public Obj
{
public:
	void UpDate();
	void Draw();
	gaze(Vec2double pos) { MapPos = pos; dead = false;}
};

