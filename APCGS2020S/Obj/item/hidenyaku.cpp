#include "hidenyaku.h"

void hidenyaku::UpDate()
{
	if (lpitem.checkHitItem(MapPos))
	{
		lpplayer.plHP = 20;
		dead = false;
		return;
	}
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpitem.itemImage[static_cast<int>(ITEM_ID::HIDENYAKU)], LAYER::ITEM, 996));
}
