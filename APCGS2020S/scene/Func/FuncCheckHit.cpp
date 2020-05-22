#include "FuncCheckHit.h"
#include "../GameScene.h"
#include "../../manager/SceneManage.h"

bool FuncCheckHit::operator()(Vec2double pos,Vec2Int size)
{
	std::vector<int> Map;
	Map.resize((MapSize.x/32+1) * (MapSize.y / 32+1));
	//Map = GameScene().GetMap();

	//if (Map[((pos.y-size.y/2)/32*MapSize.x/32+(pos.x-size.x/2)/32)] != 0)
	//{
	//	return true;
	//}
	//if (Map[(pos.y - size.y / 2)/32 * MapSize.x / 32 + (pos.x + size.x / 2)/32] != 0)
	//{
	//	return true;
	//}
	//if (Map[(pos.y + size.y / 2)/32 * MapSize.x / 32 + (pos.x - size.x / 2)/32] != 0)
	//{
	//	return true;
	//}
	//if (Map[(pos.y + size.y / 2)/32 * MapSize.x / 32 + (pos.x + size.x / 2)/32] != 0)
	//{
	//	return true;
	//}

	return false;
}