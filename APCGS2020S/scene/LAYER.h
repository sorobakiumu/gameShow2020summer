
#pragma once
enum class LAYER
{
	BG,
	MAP,
	PLAYER,
	ENEMY,
	ITEM,
	UI,
	MAX,
};

LAYER begin(LAYER);
LAYER end(LAYER);
LAYER operator++(LAYER& key);
LAYER operator*(LAYER key);