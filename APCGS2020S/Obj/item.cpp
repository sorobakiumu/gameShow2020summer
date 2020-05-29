#include "item.h"
#include "../manager/CheckHitManage.h"
#include <DxLib.h>


item* item::sInstance = nullptr;

void item::Draw()
{
}

void item::SysInit()
{
	itemImage[static_cast<int>(ITEM_ID::BANSOUKOU)] = LoadGraph("image/絆創膏.png");
	itemImage[static_cast<int>(ITEM_ID::GAZE)] = LoadGraph("image/ガーゼ.png");
	itemImage[static_cast<int>(ITEM_ID::TYUSYAKI)] = LoadGraph("image/注射器.png");
	itemImage[static_cast<int>(ITEM_ID::HIDENYAKU)] = LoadGraph("image/秘伝薬.png");
	itemImage[static_cast<int>(ITEM_ID::TUMA)] = LoadGraph("image/妻.png");
	itemImage[static_cast<int>(ITEM_ID::FMJ)] = LoadGraph("image/FMJ.png");
}

item::~item()
{
}

bool item::checkHitItem(Vec2double position)
{

	if (player::GetInstance().GetPos().x + CHIP_SIZE<position.x ||
	player::GetInstance().GetPos().x > position.x + CHIP_SIZE ||
	player::GetInstance().GetPos().y + CHIP_SIZE < position.y ||
	player::GetInstance().GetPos().y > position.y + CHIP_SIZE)
	{
		return true;
	}
	return false;
}

void item::SetItem(Vec2double pos)
{
	itemList.emplace_back(new bannsoukou(pos));
	itemList.emplace_back(new gaze({ pos.x + 100,pos.y }));
	itemList.emplace_back(new tyusyaki({ pos.x + 200,pos.y }));
	itemList.emplace_back(new hidenyaku({ pos.x + 300,pos.y }));
	itemList.emplace_back(new fmj({ pos.x + 400,pos.y }));
}

void item::upData()
{
	for (auto IQue : itemList)
	{
		(*IQue).UpDate();
	}
	auto itr = std::remove_if(itemList.begin(),				// チェックの開始地点
		itemList.end(),								// チェックの終了地点
		/* ラムダ式*/  [](SharedObj& obj) {return (*obj).Getdead(); }	// removeの条件
	);
}

item::item()
{

}
