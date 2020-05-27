#include <DxLib.h>
#include "Needle.h"
#include "../../manager/SceneManage.h"

Needle::Needle()
{

}

Needle::Needle(Vec2double pos)
{
	MapPos = pos;
	Size = { 32,32 };
	ID = OBJ_ID::GIMMICK;
	G_ID = GIMMICK_ID::MAX;
	Image = LoadGraph("");
	dead = false;
	AnyFlag = false;
}

Needle::~Needle()
{

}

void Needle::UpDate()
{

}

void Needle::Draw()
{
	lpSceneMng.addDrawQue({ MapPos,1.0,0,Image,LAYER::MAP,999 });
}