#pragma once
#include "../Obj/Obj.h"


class player :
	public Obj
{
public:
	player();
	player(Vec2double pos, Vec2Int size);
	~player();										// player���޽�׸�


private:
	void Init(void);




};

