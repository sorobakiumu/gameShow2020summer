#include <DxLib.h>
#include <vector>
#include "GameScene.h"
#include "../manager/SceneManage.h"
#include "TitleScene.h"
#include "../Obj/Obj.h"
#include "Func/FuncCheckHit.h"

#include "../Obj/Gimmick/Lift.h"
#include "../Obj/Gimmick/FallLift.h"
#include "../Obj/Gimmick/FallNeedle.h"
#include "../player/player.h"
#include "..\manager\SEManage.h"


#include "../enemy/enemy/baze.h"
#include "../enemy/enemy/black.h"
#include "../enemy/enemy/boss.h"
#include "../enemy/enemy/burst.h"
#include "../enemy/enemy/ghost.h"
#include "../enemy/enemy/man.h"
#include "../enemy/enemy/rare.h"
#include "../enemy/enemy/wolf.h"


unique_Base GameScene::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		return std::move(std::make_unique<TitleScene>());
	}

	int Cnt=0;
	for (auto obj : ObjList)
	{
		obj->UpDate();
		if (obj->GetID()==OBJ_ID::PLAYER)
		{
			obj->SetPos(CheckHit(obj->GetPos(), obj->GetSize(),0));
			plPos = obj->GetPos();
		}
		Cnt++;
	}
	if (plPos.x >= ScrCenter.x && plPos.x <= MapSize.x-ScrCenter.x)
	{
		MapPos = { MapSize.x/2 - plPos.x+ScrCenter.x,ScrCenter.y };
	}
	if (MapPos.x == 0)
	{
		bool test= true;
	}

	if (MapPos.x<-MapSize.x+ScrCenter.x)
	{
		MapPos.x = -MapSize.x + ScrCenter.x;
	}
	else if (MapPos.x>MapSize.x/2)
	{
		MapPos.x = MapSize.x/2;
	}

	lpSceneMng.addDrawQue(std::make_tuple(MapPos,1.0,0.0,MapScreen,LAYER::BG,0));

	auto itr = std::remove_if(ObjList.begin(),				// チェックの開始地点
		ObjList.end(),								// チェックの終了地点
		/* ラムダ式*/  [](SharedObj& obj) {return (*obj).Getdead(); }	// removeの条件
	);

	for (auto obj:ObjList)
	{
		obj->Draw();
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

Vec2double GameScene::CheckHit(Vec2double pos, Vec2Int size,int Cnt)
{
	if (Cnt>=20)
	{
		return pos;
	}
	bool Check[4] = { false,false,false,false };
	if (Map[static_cast<int>((pos.y-size.y/2)/32)][static_cast<int>((pos.x-size.x/2)/32)] > 0)
	{
		Check[0] = true;
	}
	if (Map[static_cast<int>((pos.y-size.y/2)/32)][static_cast<int>((pos.x+size.x/2)/32)] > 0)
	{
		Check[1] = true;
	}
	if (Map[static_cast<int>((pos.y+size.y/2)/32)][static_cast<int>((pos.x-size.x/2)/32)] > 0)
	{
		Check[2] = true;
	}
	if (Map[static_cast<int>((pos.y+size.y/2)/32)][static_cast<int>((pos.x+size.x/2)/32)] > 0)
	{
		Check[3] = true;
	}

	// 4隅の状態を獲得(当たってるかどうか)
	if (Check[0] == true&&Check[2] == true)
	{
		return CheckHit({ pos.x + 1,pos.y }, size, Cnt + 1);
	}
	else if (Check[1] == true&&Check[3] == true)
	{
		return CheckHit({ pos.x - 1,pos.y }, size, Cnt + 1);
	}

	if (Check[0]==true&&Check[1]==true)
	{
		return CheckHit({ pos.x,pos.y + 1 }, size,Cnt+1);
	}
	else if (Check[2] == true&&Check[3] == true)
	{
 		return CheckHit({ pos.x,pos.y - 1 }, size,Cnt + 1);
	}



	return pos;
}

GameScene::GameScene()
{
	ObjList.emplace_back(new wolf());
	MapScreen = 0;
	LoadDivGraph("image/tile.png", 9, 3, 3, 32, 32, bgImage);
	ObjList.emplace_back(new Lift({ static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, { 0,static_cast<double>(ScrCenter.y) }, { static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, 300));
	ObjList.emplace_back(new FallLift({ 640.0,ScrCenter.y }, 3));
	ObjList.emplace_back(new FallNeedle({ 640.0,32.0 }));

	FILE* fp;
	fopen_s(&fp, "Data/tester.dat", "rb");
	if (fp != nullptr)
	{
		std::vector<int> map;
		int x, y, i = 0;
		fscanf(fp, "%d %d", &x, &y);
		map.resize(x * y);
		while (i < x * y)
		{
			fscanf(fp, "%d", &map[i]);
			i++;
		}
		fclose(fp);
		Map.resize(y);
		int z = 0;
		for (int i=0;i<y;i++)
		{
			Map[i].resize(x);
			for (int j=0;j<x;j++)
			{
				Map[i][j] = map[z];
				z++;
			}
		}

		MapSize = { x * 32,y * 32 };
		MapScreen = MakeScreen(MapSize.x, MapSize.y, true);
		SetDrawScreen(MapScreen);
		for (i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				DrawRotaGraph(j * 32+16, i * 32+16, 1.0, 0, bgImage[Map[i][j]], true);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
	}

	// BGM挿入
	lpSEMng.readMusic("BGM", "sound/魔王魂改変戦闘用BGM(改).mp3");

	// ﾙｰﾌﾟ有、頭から再生(BGM推奨)
	PlaySoundMem(lpSEMng.loadBGM("BGM"), DX_PLAYTYPE_LOOP, true);


	ObjList.emplace_back(new player({320,380}, { 32,32 }));
	MapPos = { MapSize.x/2-ScrCenter.x,ScrCenter.y};
}

GameScene::~GameScene()
{

}
