#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj/Obj.h"
#include "Func/FuncCheckHit.h"
#include "../enemy/Enemy.h"
#include "../Obj/Gimmick/Canon.h"

#define lpGameScene GameScene::GetInstance()

class GameScene :
	public BaseScene
{
public:
	static GameScene& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new GameScene();
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



	unique_Base Update(unique_Base own) override;			//シーンを、更新する。


	std::vector<int> GetMap() { return Map; }
	void AddObjList(SharedObj obj);

private:
	friend FuncCheckHit;
	friend Canon;

	GameScene();
	~GameScene();

	int bgImage[9];
	int MapScreen;

	std::vector<std::shared_ptr<Enemy>> enemyList;
	std::vector<SharedObj> ObjList;

	Vec2double plPos, plPosOld, MapPos;
	std::vector<int> Map;

	static GameScene* sInstance;
};
