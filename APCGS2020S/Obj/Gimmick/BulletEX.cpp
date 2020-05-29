#include "BulletEX.h"
#include "../../player/player.h"
#include "../../manager/SceneManage.h"
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
	dead = false;
	Image = LoadGraph("image/BulletX.png");
	AnyFlag = false;
}

BulletEX::~BulletEX()
{

}

void BulletEX::UpDate()
{
	Vec2double plPos = lpplayer.GetPos();
	Rad = atan2(plPos.y-MapPos.y,plPos.x-MapPos.x);
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
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, Rad, Image, LAYER::MAP, 999));
}