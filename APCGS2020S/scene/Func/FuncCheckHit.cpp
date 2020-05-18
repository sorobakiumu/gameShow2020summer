#include "FuncCheckHit.h"
#include "../GameScene.h"

void FuncCheckHit::operator()(int no, void* scene)
{
	int Cnt = 0;
	for (auto obj : ((GameScene*)scene)->ObjList)
	{
		if (Cnt == no)
		{
			Size = obj->GetSize();
			while (CheckHit[0]||CheckHit[1]||CheckHit[2]||CheckHit[3])
			{
				Pos = obj->GetPos();


				Vec2Int mapSize = { ((GameScene*)scene)->MapSize.x / 32,((GameScene*)scene)->MapSize.y / 32 };

				if (((GameScene*)scene)->Map[((Pos.y - Size.y / 2) / 32) * mapSize.x + ((Pos.x - Size.x / 2) / 32)] != 0)
				{
					CheckHit[0] = true;
				}
				if (((GameScene*)scene)->Map[((Pos.y - Size.y / 2) / 32) * mapSize.x + ((Pos.x + Size.x / 2) / 32)] != 0)
				{
					CheckHit[1] = true;
				}
				if (((GameScene*)scene)->Map[((Pos.y + Size.y / 2) / 32) * mapSize.x + ((Pos.x - Size.x / 2) / 32)] != 0)
				{
					CheckHit[2] = true;
				}
				if (((GameScene*)scene)->Map[((Pos.y + Size.y / 2) / 32) * mapSize.x + ((Pos.x + Size.x / 2) / 32)] != 0)
				{
					CheckHit[3] = true;
				}

				if (CheckHit[0] == true || CheckHit[2] == true)
				{
					obj->SetPos({ Pos.x + 1,Pos.y });
					Pos = obj->GetPos();
				}
				if (CheckHit[1] == true || CheckHit[3] == true)
				{
					obj->SetPos({ Pos.x - 1,Pos.y });
					Pos = obj->GetPos();
				}
				if (CheckHit[0] == true || CheckHit[1] == true)
				{
					obj->SetPos({ Pos.x,Pos.y+1 });
					Pos = obj->GetPos();
				}
				if (CheckHit[2] == true || CheckHit[3] == true)
				{
					obj->SetPos({ Pos.x,Pos.y - 1 });
					Pos = obj->GetPos();
				}
			}

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