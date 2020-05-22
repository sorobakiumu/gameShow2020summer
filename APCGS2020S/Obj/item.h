#pragma once
#include "Obj.h"


enum class ITEM_ID
{
	BANSOUKOU,
	GAZE,
	TYUSYAKI,
	HIDENYAKU,
	TUMA,
	FMJ,
	MAX
};



class item :
	public Obj
{
public:
	void UpDate();

private:
	
};

