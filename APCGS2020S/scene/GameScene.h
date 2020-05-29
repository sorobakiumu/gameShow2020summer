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

	bool CheckFall(Vec2double pos,Vec2Int size);
private:
	friend Canon;
	void CheckEnemy(double posx);
	std::vector<SharedObj> ObjList;
};
