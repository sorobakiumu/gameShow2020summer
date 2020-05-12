#pragma once
#include <Windows.h>
#include "../Common/Vector2.h"

class SceneManage
{
public:
	static SceneManage& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneManage();
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

	const Vec2Int ScreenSize;
	Vec2Int ScreenCenter;

	void Run();
private:
	static SceneManage* sInstance;

	SceneManage();
	~SceneManage();

	bool SysInit();

};
