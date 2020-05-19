#include "FuncCheckHit.h"
#include "../GameScene.h"
#include "../SceneManage.h"

void FuncCheckHit::operator()(int no, void* scene,Vec2double pos)
{
	int Cnt = 0;
	for (auto obj : ((GameScene*)scene)->ObjList)
	{
		if (Cnt == no)
		{
			Size = obj->GetSize();
			MapPos = { (((GameScene*)scene)->MapSize.x / 2 - ((GameScene*)scene)->MapPos.x) + obj->GetPos().x,obj->GetPos().y };
			// プレイヤーのサイズと座標(マップ座標)を取得する
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
			//switch (obj->GetG_ID())
			//{
			//default:
			//	break;
			//}
			//break;
		case OBJ_ID::ITEM:

			break;
		default:
			break;
		}
	}

}