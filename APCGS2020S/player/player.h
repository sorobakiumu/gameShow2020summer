#pragma once
#include "../Obj/Obj.h"

class player :
	public Obj
{
public:
	player();									// ºİ½Ä×¸À
	player(Vec2double pos, Vec2Int size);		// w’è•t‚«ºİ½Ä×¸À
	~player();									// player‚ÌÃŞ½Ä×¸À


private:

	void Init(void);							// ‰Šú‰»ŠÖ”


};

