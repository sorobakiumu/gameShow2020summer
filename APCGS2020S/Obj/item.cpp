#include "item.h"
#include "../manager/CheckHitManage.h"
#include <DxLib.h>

item* item::sInstance = nullptr;

void item::UpDate()
{
}

void item::Draw()
{
}

void item::SysInit()
{
	itemImage[static_cast<int>(ITEM_ID::BANSOUKOU)] = LoadGraph("image/„Jënçp.png");
	itemImage[static_cast<int>(ITEM_ID::GAZE)] = LoadGraph("image/ÉKÅ[É[.png");
	itemImage[static_cast<int>(ITEM_ID::TYUSYAKI)] = LoadGraph("image/íçéÀäÌ.png");
	itemImage[static_cast<int>(ITEM_ID::HIDENYAKU)] = LoadGraph("image/îÈì`ñÚ.png");
	itemImage[static_cast<int>(ITEM_ID::TUMA)] = LoadGraph("image/ç».png");
	itemImage[static_cast<int>(ITEM_ID::FMJ)] = LoadGraph("image/FMJ.png");
}

item::~item()
{
}

item::item()
{

}
