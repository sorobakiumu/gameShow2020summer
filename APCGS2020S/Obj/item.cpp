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
	itemImage[static_cast<int>(ITEM_ID::BANSOUKOU)] = LoadGraph("image/�J�n�p.png");
	itemImage[static_cast<int>(ITEM_ID::GAZE)] = LoadGraph("image/�K�[�[.png");
	itemImage[static_cast<int>(ITEM_ID::TYUSYAKI)] = LoadGraph("image/���ˊ�.png");
	itemImage[static_cast<int>(ITEM_ID::HIDENYAKU)] = LoadGraph("image/��`��.png");
	itemImage[static_cast<int>(ITEM_ID::TUMA)] = LoadGraph("image/��.png");
	itemImage[static_cast<int>(ITEM_ID::FMJ)] = LoadGraph("image/FMJ.png");
}

item::~item()
{
}

item::item()
{

}
