#include <DxLib.h>
#include "../Obj.h"
#include "Canon.h"
#include "../../manager/SceneManage.h"
#include "../../scene/GameScene.h"
#include "Bullet.h"

Canon::Canon()
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::CANON;
	MapPos = { 0,0 };
	Size = { 0,0 };
	Rad = 0;
	Speed = 0;
	dead = false;
	Image = 0;
	Cnt = 0;
}

Canon::Canon(Vec2double pos, double rad,int speed)
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::CANON;
	MapPos = pos;
	Size = { 32,32 };
	Rad = rad;
	Speed = speed;
	dead = false;
	Image = LoadGraph("image/CANON.png");
	Cnt = 0;
}

Canon::~Canon()
{

}

void Canon::UpDate()
{
	Cnt++;
	if (Cnt>=Speed)
	{
		Cnt = 0;
		//GameScene().AddObjList(new Bullet(MapPos,5,Rad));
	}
}

void Canon::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0,Rad, Image, LAYER::MAP, 999));
}