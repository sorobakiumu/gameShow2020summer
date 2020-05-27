#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj/Obj.h"

//#include "../enemy/Enemy.h"
#include "../Obj/Gimmick/Canon.h"

enum class PL_POS
{
	LOW,
	CENTER,
	HIGH,
	BOSS,
	MAX,
};




class GameScene :
	public BaseScene
{
public:

	GameScene();
	~GameScene();
	unique_Base Update(unique_Base own) override;			//シーンを、更新する。

	void AddObjList(SharedObj obj);

	Vec2double CheckHit(Vec2double pos, Vec2Int size,int Cnt);


private:
	friend Canon;

	int bgImage[9];
	int MapScreen;

	void CheckEnemy(Vec2double pos);

	std::vector<SharedObj> ObjList;

	Vec2double plPos, plPosOld, MapPos;
	std::vector<std::vector<int>> Map;
};
