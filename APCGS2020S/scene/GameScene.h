#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj/Obj.h"

class GameScene :
	public BaseScene
{
public:
	unique_Base Update(unique_Base own) override;			//シーンを、更新する。
	GameScene();
	~GameScene();
private:
	int bgImage[9];
	int MapScreen;
	std::vector<SharedObj> ObjList;
	std::vector<int> Map;
	Vec2double plPos, MapPos,MapSize;
};
