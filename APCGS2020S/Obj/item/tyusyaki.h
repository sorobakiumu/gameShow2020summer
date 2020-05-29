#pragma once
#include "../Obj.h"
#include"../item.h"
class tyusyaki :
	public Obj
{
public:
	void UpDate();
	void Draw();
	tyusyaki(Vec2double pos) { MapPos = pos; dead = false; }
};

