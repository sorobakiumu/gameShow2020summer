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
	itemImage[static_cast<int>(ITEM_ID::BANSOUKOU)] = LoadGraph("image/ใJnp.png");
	itemImage[static_cast<int>(ITEM_ID::GAZE)] = LoadGraph("image/K[[.png");
	itemImage[static_cast<int>(ITEM_ID::TYUSYAKI)] = LoadGraph("image/หํ.png");
	itemImage[static_cast<int>(ITEM_ID::HIDENYAKU)] = LoadGraph("image/้`๒.png");
	itemImage[static_cast<int>(ITEM_ID::TUMA)] = LoadGraph("image/ศ.png");
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
	for (auto IQue : itemList)
	{
		(*IQue).SetPos(pos);
		(*IQue).SetDead(false);
	}
}

void item::upData()
{
	for (auto IQue : itemList)
	{
		(*IQue).UpDate();
	}
	auto itr = std::remove_if(itemList.begin(),				// `FbNฬJnn_
		itemList.end(),								// `FbNฬIนn_
		/* _ฎ*/  [](SharedObj& obj) {return (*obj).Getdead(); }	// removeฬ๐
	);
}

item::item()
{

}
