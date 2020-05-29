#include "BulletEX.h"
#include "../../player/player.h"

BulletEX::BulletEX()
{
	MapPos = { 0,0 };
	Size = { 0,0 };
	Speed = 0;
	Rad = 0;
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::BULLET_EX;
	dead = true;
	Image = 0;
	AnyFlag = false;
}

BulletEX::BulletEX(Vec2double pos, double rad, int speed)
{
	MapPos = pos;
	Size = { 32,32 };
	Speed = speed;
	Rad = rad;
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::BULLET_EX;
	dead = true;
	Image = 0;
	AnyFlag = false;
}

BulletEX::~BulletEX()
{

}

void BulletEX::UpData()
{
	Vec2double plPos = player().GetPos();
	Rad = atan2(MapPos.y-plPos.y,MapPos.x-plPos.x);
	MapPos.x += cos(Rad) * Speed;
	MapPos.y += sin(Rad) * Speed;
	if (MapPos.x <= Size.x / 2 || MapPos.x >= MapSize.x + Size.x / 2 ||
		MapPos.y <= Size.y / 2 || MapPos.y >= MapSize.y + Size.y / 2)
	{
		dead = true;
	}
}

void BulletEX::Draw()
{

}