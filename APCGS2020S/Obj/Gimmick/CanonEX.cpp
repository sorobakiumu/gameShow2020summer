#include "CanonEX.h"
#include "../../manager/SceneManage.h"

CanonEX::CanonEX()
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::CANON_EX;
	MapPos = { 0,0 };
	Size = { 0,0 };
	Rad = 0;
	Speed = 0;
	dead = false;
	Image = 0;
	Cnt = 0;
	AnyFlag = false;
}

CanonEX::CanonEX(Vec2double pos, double rad, int speed)
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::CANON_EX;
	MapPos = pos;
	Size = { 32,32 };
	Rad = rad;
	Speed = speed;
	dead = false;
	Image = LoadGraph("image/CanonX.png");
	Cnt = 0;
	AnyFlag = false;
}

CanonEX::~CanonEX()
{

}

void CanonEX::UpDate()
{
	Cnt++;
	if (Cnt>=Speed)
	{
		Cnt = 0;
		AnyFlag = true;
	}
}

void CanonEX::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, Rad, Image, LAYER::MAP, 999));
}