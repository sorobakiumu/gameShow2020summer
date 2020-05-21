#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj/Obj.h"
#include "Func/FuncCheckHit.h"
#include "../enemy/Enemy.h"

class GameScene :
	public BaseScene
{
public:
	unique_Base Update(unique_Base own) override;			//シーンを、更新する。
	GameScene();
	~GameScene();
private:
	friend FuncCheckHit;

	int bgImage[9];
	int MapScreen;

	std::vector<std::shared_ptr<Enemy>> enemyList;
	std::vector<SharedObj> ObjList;
	static std::vector<int> Map;
	Vec2double plPos,plPosOld, MapPos;
};
