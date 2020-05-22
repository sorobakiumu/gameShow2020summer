#include "FuncCheckHit.h"
#include "../GameScene.h"
#include "../../manager/SceneManage.h"

bool FuncCheckHit::operator()(Vec2double pos,Vec2Int size)
{
	//if (GameScene::Map[(pos.y-size.y/2)*MapSize.x/32+(pos.x-size.x/2)] != 0)
	//{
	//	return true;
	//}
	//if (GameScene::Map[(pos.y - size.y / 2) * MapSize.x / 32 + (pos.x + size.x / 2)] != 0)
	//{
	//	return true;
	//}
	//if (GameScene::Map[(pos.y + size.y / 2) * MapSize.x / 32 + (pos.x - size.x / 2)] != 0)
	//{
	//	return true;
	//}
	//if (GameScene::Map[(pos.y + size.y / 2) * MapSize.x / 32 + (pos.x + size.x / 2)] != 0)
	//{
	//	return true;
	//}
	return false;
}