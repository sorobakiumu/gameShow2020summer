#pragma once

enum class GIMMICK_ID
{
	NON,
	LIFT,
	FALL_LIFT,
	NEEDLE,
	FALLNEEDLE,
	CANON,
	BULLET,
	GENERATOR,
	MAX,
};

#include "../Obj.h"

class Gimmick :
	public Obj
{
public:
	Gimmick();
	~Gimmick();

protected:
};

