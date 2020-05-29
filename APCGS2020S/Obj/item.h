#pragma once
#include "../manager/SceneManage.h"
#include "../player/player.h"

#include "item/bannsoukou.h"
#include "item/fmj.h"
#include "item/gaze.h"
#include "item/hidenyaku.h"
#include "item/tyusyaki.h"

#define lpitem item::GetInstance()

enum class ITEM_ID
{
	BANSOUKOU,
	GAZE,
	TYUSYAKI,
	HIDENYAKU,
	TUMA,
	FMJ,
	MAX
};



class item
{
public:
	void Draw();
	void SysInit();
	static item& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new item();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}
	int itemImage[static_cast<int>(ITEM_ID::MAX)];

	bool checkHitItem(Vec2double position);

	void SetItem(Vec2double pos);

	void upData();

private:
	static item* sInstance;
	std::vector<SharedObj> itemList;
	item();
	~item();
};

