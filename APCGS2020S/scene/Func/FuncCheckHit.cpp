#include "FuncCheckHit.h"
#include "../GameScene.h"
#include "../../manager/SceneManage.h"

bool FuncCheckHit::CheckHit(Vec2double pos,Vec2Int size)
{
	std::vector<int> Map;
	Map.resize((MapSize.x/32+1) * (MapSize.y / 32+1));



	return false;
}

FuncCheckHit::FuncCheckHit()
{
}

FuncCheckHit::~FuncCheckHit()
{
}

void FuncCheckHit::SetMap(Vec2Int size, std::vector<int> Map)
{
	map.resize(size.x/32*size.y/32);
	map = Map;
}