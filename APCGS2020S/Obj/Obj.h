#pragma once
#include "../Common/Vector2.h"

enum class OBJ_ID
{
	PLAYER,
	ENEMY,
	ITEM,
	GIMMICK,
	MAX,
};

class Obj
{
public:
	Obj();
	virtual ~Obj();

	const OBJ_ID GetID()const { return ID; };
	const Vec2double GetPos()const { return Pos; };
	const Vec2Int GetSize()const { return Size; };

	void SetPos(Vec2double pos) { Pos = pos; };

protected:
	OBJ_ID ID;
	Vec2double Pos;
	Vec2Int Size;
};

