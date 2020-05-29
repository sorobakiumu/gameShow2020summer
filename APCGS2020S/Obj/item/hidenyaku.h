#pragma once
#include "../Obj.h"
#include"../item.h"
class hidenyaku :
	public Obj
{
public:
	void UpDate();
	void Draw();
	hidenyaku(Vec2double pos) { MapPos = pos; dead = false; }
};

