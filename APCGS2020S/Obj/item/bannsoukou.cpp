#include "bannsoukou.h"

void bannsoukou::UpDate()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpitem.itemImage[static_cast<int>(ITEM_ID::BANSOUKOU)], LAYER::ITEM, 996));
}
