#include "Generator.h"
#include "../../manager/SceneManage.h"

Generator::Generator()
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::GENERATOR;
	MapPos = { -100,-100 };
	Size = { 0,0 };
	Image = 0;
	dead = false;
	AnyFlag = false;
	FCnt = 0;
	Speed = 0;
	GCnt = 10;
	Rad = 0;
}

Generator::Generator(Vec2double pos,int speed)
{
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::GENERATOR;
	MapPos = pos;
	Size = { 32,32 };
	Image = LoadGraph("image/HOLE.png");
	dead = false;
	AnyFlag = false;
	Speed = speed;
	FCnt = 0;
	Rad = 0;
	GCnt = 0;
}

Generator::~Generator()
{

}

void Generator::UpDate()
{
	AnyFlag = false;
	FCnt++;
	if (FCnt >= Speed)
	{
		FCnt = 0;
		GCnt++;
		AnyFlag = true;
		if (GCnt >=10)
		{
			dead = true;
		}
	}
}

void Generator::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image, LAYER::MAP, 999));
}