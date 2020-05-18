#include "FuncCheckHit.h"
#include "../GameScene.h"

void FuncCheckHit::operator()(int no, void* scene)
{
	int Cnt = 0;
	for (auto obj : ((GameScene*)scene)->ObjList)
	{
		if (Cnt == no)
		{
			Pos = obj->GetPos();
			Size = obj->GetSize();
		}
		Cnt++;
	}

	for (auto obj : ((GameScene*)scene)->ObjList)
	{
		switch (obj->GetID())
		{
		case OBJ_ID::ENEMY:

			break;
		case OBJ_ID::GIMMICK:

			break;
		case OBJ_ID::ITEM:

			break;
		default:
			break;
		}
	}


}