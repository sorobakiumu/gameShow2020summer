#pragma once
#include "Gimmick.h"
class FallLift :
	public Gimmick
{
public:
	FallLift();
	FallLift(Vec2double pos,int speed);
	~FallLift();
	void UpDate();
	void Draw();
private:
	int Speed;
	bool FallFlag;
	int Image;
};

