#pragma once
#include "../Obj.h"

enum class GIMMICK_ID
{
	LIFT,
	FALL_LIFT,
	MAX,
};

class Gimmick :
	public Obj
{
public:
	Gimmick();
	~Gimmick();

	virtual void UpDate() = 0;
protected:
	GIMMICK_ID G_ID;
};

