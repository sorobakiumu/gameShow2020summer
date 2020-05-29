#include "tyusyaki.h"

void tyusyaki::UpDate()
{
	if (lpitem.checkHitItem(MapPos))
	{
		if (20 < lpplayer.plHP + 10)
		{
			lpplayer.plHP = 20;
		}
		else {
			lpplayer.plHP += 10;
		}
		dead = false;
		return;
	}
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpitem.itemImage[static_cast<int>(ITEM_ID::TYUSYAKI)], LAYER::ITEM, 996));
}

void tyusyaki::Draw()
{
}
