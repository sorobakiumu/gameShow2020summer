#include "bannsoukou.h"

void bannsoukou::UpDate()
{
	if (lpitem.checkHitItem(MapPos))
	{
		if (20 < lpplayer.plHP + 3)
		{
			lpplayer.plHP = 20;
		}
		else{
			lpplayer.plHP += 3;
		}
		dead = false;
		return;
	}
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpitem.itemImage[static_cast<int>(ITEM_ID::BANSOUKOU)], LAYER::ITEM, 996));
}
