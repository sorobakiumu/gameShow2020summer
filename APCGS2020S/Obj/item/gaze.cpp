#include "gaze.h"

void gaze::UpDate()
{
	if (lpitem.checkHitItem(MapPos))
	{
		if (20 < lpplayer.plHP + 5)
		{
			lpplayer.plHP = 20;
		}
		else {
			lpplayer.plHP += 5;
		}
		dead = false;
		return;
	}
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpitem.itemImage[static_cast<int>(ITEM_ID::GAZE)], LAYER::ITEM, 996));
}
