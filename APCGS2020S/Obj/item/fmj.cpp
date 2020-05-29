#include "fmj.h"

void fmj::UpDate()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpitem.itemImage[static_cast<int>(ITEM_ID::FMJ)], LAYER::ITEM, 996));
}

void fmj::Draw()
{
}
