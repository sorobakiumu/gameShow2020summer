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
protected:
	GIMMICK_ID G_ID;
};

