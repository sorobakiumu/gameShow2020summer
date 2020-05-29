#pragma once
#include "../Common/Vector2.h"
#include "Vector"
#include "SceneManage.h"
#include <DxLib.h>

#define lpMapMng MapMnager::GetInstance()

class MapMnager
{
public:

	static MapMnager& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new MapMnager();
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

	Vec2double HitCheck(Vec2double pos, Vec2Int size, int Cnt);
	void SetPos(Vec2double pos) { _pos = pos; }
	Vec2double GetPos() { return _pos; }
	int MapScreen;
	void SysInit();
private:
	Vec2double _pos;
	int bgImage[9];
	static MapMnager* sInstance;
	Vec2double plPos, plPosOld, MapPos;
	std::vector<std::vector<int>> Map;
};

