#include <DxLib.h>
#include <vector>
#include "GameScene.h"
#include "../manager/SceneManage.h"
#include "../manager/MapMnager.h"
#include "TitleScene.h"
#include "../Obj/Obj.h"

#include "../Obj/Gimmick/Lift.h"
#include "../Obj/Gimmick/FallLift.h"
#include "../Obj/Gimmick/Needle.h"
#include "../Obj/Gimmick/FallNeedle.h"
#include "../Obj/Gimmick/Generator.h"
#include "../Obj/Gimmick/Canon.h"
#include "../Obj/Gimmick/Bullet.h"
#include "../Obj/Gimmick/CanonEX.h"
#include "../Obj/Gimmick/BulletEX.h"
#include "../player/player.h"
#include "..\manager\SEManage.h"


#include "../enemy/Enemy.h"

unique_Base GameScene::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		return std::move(std::make_unique<TitleScene>());
	}

	int ECnt=0;
	int tmp;
	Vec2double plPos;
	
	Vec2Int size = { CHIP_SIZE,CHIP_SIZE };
	for (auto obj : ObjList)
	{
		if (((*obj).GetID() != OBJ_ID::ENEMY) && ((*obj).GetID() != OBJ_ID::FRY_ENEMY))
		{
			obj->UpDate();
		}
		switch (obj->GetID())
		{
		case OBJ_ID::PLAYER:
			obj->SetPos(lpMapMng.HitCheck(obj->GetPos(), obj->GetSize(), 0));
			plPos = obj->GetPos();
			if (1)
			{
				// 落下処理
				int Cnt = 0;
				while ((CheckFall(obj->GetPos(), obj->GetSize()) == false) && (Cnt < 3))
				{
					obj->SetPos({ obj->GetPos().x, obj->GetPos().y + 1 });
					Cnt++;
				}
				if (CheckFall(obj->GetPos(), obj->GetSize()) == true)
				{
					obj->SetFlag(false);
				}
			}
			break;
		case OBJ_ID::GIMMICK:
			switch (obj->GetGID())
			{
			case GIMMICK_ID::CANON:
				if (obj->CheckFlag())
				{
					ObjList.emplace_back(new Bullet(obj->GetPos(), -3, obj->GetRad()));
					obj->SetFlag(false);
				}
				break;
			case GIMMICK_ID::CANON_EX:
				if (obj->CheckFlag())
				{
					ObjList.emplace_back(new BulletEX(obj->GetPos(), 3, obj->GetRad()));
					obj->SetFlag(false);
				}
				break;
			case GIMMICK_ID::GENERATOR:
				//if (obj->CheckFlag())
				//{

				//	switch (rand() % 7)
				//	{
				//	case 0:
				//		ObjList.emplace_back(new man(0.0));
				//		break;
				//	case 1:
				//		ObjList.emplace_back(new burst(0.0));
				//		break;
				//	case 2:
				//		ObjList.emplace_back(new baze(0.0));
				//		break;
				//	case 3:
				//		ObjList.emplace_back(new black(0.0));
				//		break;
				//	case 4:
				//		ObjList.emplace_back(new ghost(0.0));
				//		break;
				//	case 5:
				//		ObjList.emplace_back(new rare(0.0));
				//		break;
				//	case 6:
				//		ObjList.emplace_back(new wolf(0.0));
				//		break;
				//	}
				//	obj->SetFlag(false);
				//}
				break;
			default:
				break;

			}
			break;
		case OBJ_ID::ENEMY:
			if (lpMapMng.HitCheck(obj->GetPos(), obj->GetSize(), 0) == obj->GetPos())
			{
				// 落下処理
				tmp = 0;
				while ((CheckFall(obj->GetPos(), size) == false) && (tmp < 3))
				{
					obj->SetPos({ obj->GetPos().x, obj->GetPos().y + 1 });
					tmp++;
				}
				if (CheckFall(obj->GetPos(), size) == true)
				{
					obj->SetFlag(false);
				}			
			}
			if ((obj->GetPos().x <= 0) || (obj->GetPos().x < plPos.x - ScrSize.x * 2) ||
				(obj->GetPos().x >= plPos.x+ScrSize.x*2)||
				(obj->GetPos().y < 0) || (obj->GetPos().y<0)||obj->GetPos().y>ScrSize.y)
			{
				obj->SetDead(true);
			}
			ECnt++;
			obj->SetPos(lpMapMng.HitCheck(obj->GetPos(), obj->GetSize(), 0));
			break;
		case OBJ_ID::FRY_ENEMY:
			if ((obj->GetPos().x <= 0) || (obj->GetPos().x < plPos.x - ScrSize.x * 2) ||
			    (obj->GetPos().x>=MapSize.x)||(obj->GetPos().y < 0)||(obj->GetPos().y>ScrSize.y))
			{
				obj->SetDead(true);
			}
			ECnt++;
			break;
		default:
			break;
		}
	}

	for (auto obj : ObjList)
	{
		if (((*obj).GetID() == OBJ_ID::ENEMY) || ((*obj).GetID() == OBJ_ID::FRY_ENEMY))
		{
			if ((*obj).GetPos().x-plPos.x<ScrCenter.x*2)
			{
				obj->UpDate();
			}
		}
	}


	if (plPos.x >= ScrCenter.x && plPos.x <= MapSize.x-ScrCenter.x)
	{
		lpMapMng.SetPos({ MapSize.x/2 - plPos.x+ScrCenter.x,ScrCenter.y });
	}

	if (lpMapMng.GetPos().x<-MapSize.x+ScrCenter.x)
	{
		lpMapMng.SetPos({ lpMapMng.GetPos().y ,-MapSize.x + ScrCenter.x });
	}
	else if (lpMapMng.GetPos().x >MapSize.x/2)
	{
		lpMapMng.SetPos({ lpMapMng.GetPos().y ,static_cast<double>(MapSize.x / 2 )});
	}

	lpSceneMng.addDrawQue(std::make_tuple(lpMapMng.GetPos(),1.0,0.0, lpMapMng.MapScreen,LAYER::BG,0));

	auto itr = std::remove_if(ObjList.begin(),				// チェックの開始地点
		ObjList.end(),								// チェックの終了地点
		/* ラムダ式*/  [](SharedObj& obj) {return (*obj).Getdead(); }	// removeの条件
	);

	for (auto obj:ObjList)
	{
		if(obj!=nullptr)
		{
			obj->Draw();
		}
	}

	ObjList.erase(itr,
		ObjList.end());
	//Vec2double MSizeD;
	//MSizeD = { static_cast<double>(MapSize.x),static_cast<double>(MapSize.y) };
	//lpSceneMng.addDrawQue(std::make_tuple(MSizeD, 1.0, 0.0,0, LAYER::MAX, 0));
	return std::move(own);
}

void GameScene::AddObjList(SharedObj obj)
{
	ObjList.emplace_back(obj);
}


bool GameScene::CheckFall(Vec2double pos, Vec2Int size)
{
	if (lpMapMng.HitCheck ({ pos.x,pos.y + 1 }, size, 0)==pos)
	{
		return true;
	}
	return false;
}

void GameScene::CheckEnemy(double posx)
{

	PL_POS plPos = PL_POS::LOW;
	if (posx < 500)
	{
		plPos = PL_POS::CENTER;
	}
	else if(posx < 999)
	{
		plPos = PL_POS::HIGH;
	}
	else
	{
		plPos = PL_POS::BOSS;
	}


		switch (plPos)
	{
	case (PL_POS::LOW):
		//if (rand() % 300 == 0)
		{
			ObjList.emplace_back(new man(posx));
			ObjList.emplace_back(new ghost(posx));
			ObjList.emplace_back(new wolf(posx));
		}
		break;
	case (PL_POS::CENTER):
		ObjList.emplace_back(new burst(posx));
		ObjList.emplace_back(new rare(posx));
		ObjList.emplace_back(new black(posx));
		ObjList.emplace_back(new man(posx));
		ObjList.emplace_back(new ghost(posx));
		ObjList.emplace_back(new wolf(posx));
		break;
	case (PL_POS::HIGH):
		//ObjList.emplace_back(new baze(posx));
		//ObjList.emplace_back(new rare(posx));
		//ObjList.emplace_back(new burst(posx));
		//ObjList.emplace_back(new black(posx));
		//ObjList.emplace_back(new man(posx));
		//ObjList.emplace_back(new ghost(posx));
		//ObjList.emplace_back(new wolf(posx));
		break;
	case (PL_POS::BOSS):
		ObjList.emplace_back(new boss(posx));
		break;
	default:
		break;
	}
}

GameScene::GameScene()
{

		CheckEnemy(100);


	lpMapMng.MapScreen = 0;

	ObjList.emplace_back(new player({ 320,380 }, { 32,32 }));
	ObjList.emplace_back(new Lift({ static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, { 0,static_cast<double>(ScrCenter.y) }, { static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, 300));
	ObjList.emplace_back(new FallLift({ 640.0,ScrCenter.y }, 3));
	ObjList.emplace_back(new FallNeedle({ 640.0,32.0 }));
	ObjList.emplace_back(new Generator({480.0,120.0},120));
	ObjList.emplace_back(new CanonEX({ 480,360 }, 1.0, 120));

	lpMapMng.SysInit();

	// BGM挿入
	lpSEMng.readMusic("BGM", "sound/魔王魂改変戦闘用BGM(改).mp3");

	// ﾙｰﾌﾟ有、頭から再生(BGM推奨)
	PlaySoundMem(lpSEMng.loadBGM("BGM"), DX_PLAYTYPE_LOOP, true);
}

GameScene::~GameScene()
{

}
