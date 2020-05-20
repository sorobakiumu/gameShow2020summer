#include "FuncCheckHit.h"
#include "../GameScene.h"
#include "../SceneManage.h"

bool FuncCheckHit::operator()(int no, void* scene)
{
	int Cnt = 0;
	for (auto obj : ((GameScene*)scene)->ObjList)
	{
		if (Cnt == no)
		{
			plSize = obj->GetSize();
			plPos = obj->GetPos();
			// �v���C���[�̃T�C�Y�ƍ��W���擾����
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
			ObjPos = obj->GetPos();
			ObjSize = obj->GetSize();
			if ((((plPos.x-plSize.x/2)<(ObjPos.x+ObjSize.x/2))&&((plPos.x+plSize.x/2)>(ObjPos.x-ObjSize.x/2))
			   ||((plPos.x+plSize.x/2)<(ObjPos.x-ObjSize.x/2))&&((plPos.x-plSize.x/2)>(ObjPos.x+ObjSize.x/2)))
			  &&(((plPos.y-plSize.y/2)<(ObjPos.y+ObjSize.y/2))&&((plPos.y+plSize.y/2)>(ObjPos.y-ObjSize.y/2))
			   ||((plPos.y+plSize.y/2)<(ObjPos.y-ObjSize.y/2))&&((plPos.y-plSize.y/2)>(ObjPos.y+ObjSize.y/2)))
				)
			{
				return true;
			}
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