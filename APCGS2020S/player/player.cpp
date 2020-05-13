#include "player.h"

player::player()
{
	// ‰Šú‰»
	Init();

}

player::player(Vec2double _pos, Vec2Int _size)
{
	Pos = _pos;
	Size = _size;
	ID = OBJ_ID::PLAYER;

	Init();
}

player::~player()
{
}

void player::Init(void)
{
}
