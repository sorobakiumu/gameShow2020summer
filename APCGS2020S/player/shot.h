#pragma once
#include "player.h"
#include "../Common/Vector2.h"

class shot :
	public Obj
{
	// ŠÖ”
	shot();												// ºİ½Ä×¸À
	shot(Vec2double pos, Vec2Int size, PLSTATE _state);	// w’è•t‚«ºİ½Ä×¸À
	~shot();
	bool shotMove(void);								// UŒ‚§Œä
	void Init(void);									// ‰Šú‰»

	void Draw();

	// •Ï”
	PLSTATE plState;									// ó‘ÔŠi”[•Ï”

private:
	Vec2double startPos;

};

