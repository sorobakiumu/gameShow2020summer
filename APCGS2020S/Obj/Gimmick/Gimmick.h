#pragma once
#include "../Obj.h"

enum class GIMMICK_ID
{
	LIFT,
	FALL_LIFT,
	NEEDLE,
	FALLNEEDLE,
	CANON,
	BULLET,
	GENERATOR,
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

