#include <math.h>
#include "Bullet.h"
#include "../../manager/SceneManage.h"

Bullet::Bullet()
{
	MapPos = { 0,0 };
	Size = {0,0};
	Speed = 0;
	Rad = 0;
	ID = OBJ_ID::GIMMICK;
	G_ID=GIMMICK_ID::BULLET;
	dead = true;
	Image = 0;
	AnyFlag = false;
}

Bullet::Bullet(Vec2double pos,int speed,double rad)
{
	MapPos = pos;
	Size = { 32,32 };
	Speed = speed;
	Rad = rad;
	ID = OBJ_ID::GIMMICK;
	G_ID=GIMMICK_ID::BULLET;
	dead = false;
	Image = 0;
	AnyFlag = false;
}

Bullet::~Bullet()
{
}

void Bullet::UpDate()
{
	MapPos.x += cos(Rad) * Speed;
	MapPos.y += sin(Rad) * Speed;
	if (MapPos.x<=Size.x/2||MapPos.x>=MapSize.x+Size.x/2||
		MapPos.y<=Size.y/2||MapPos.y>=MapSize.y+Size.y/2)
	{
		dead = true;
	}
}

void Bullet::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0,Rad, Image, LAYER::MAP, 999));
}