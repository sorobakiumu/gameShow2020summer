#include <DxLib.h>
#include <vector>
#include "GameScene.h"
#include "../manager/SceneManage.h"
#include "TitleScene.h"
#include "../Obj/Obj.h"

#include "../Obj/Gimmick/Lift.h"
#include "../Obj/Gimmick/FallLift.h"
#include "../Obj/Gimmick/FallNeedle.h"
#include "../player/player.h"
#include "..\manager\SEManage.h"


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
			if (FuncCheckHit()(obj->GetPos(), obj->GetSize()))
			{
				
			}
			// ObjListの何番目かとゲームシーンのポインタを渡す
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
	for (auto enemy : enemyList)
	{
		(*enemy).UpDate();
	}

	// ﾙｰﾌﾟ有、頭から再生(BGM推奨)
	PlaySoundMem(lpSEMng.loadBGM("BGM"), DX_PLAYTYPE_LOOP, true);


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


GameScene::GameScene()
{
	MapScreen = 0;

	enemyList.emplace_back(new Enemy(ENEMY_ID::BOSS));
	LoadDivGraph("image/tile.png", 9, 3, 3, 32, 32, bgImage);
	ObjList.emplace_back(new Lift({ static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, { 0,static_cast<double>(ScrCenter.y) }, { static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, 300));
	ObjList.emplace_back(new FallLift({ 640.0,ScrCenter.y},3));
	ObjList.emplace_back(new FallNeedle({640.0,32.0}));

	FILE* fp;
	fopen_s(&fp,"Data/tester.dat","rb");
 	if (fp != nullptr)
	{
		int x, y,i=0;
		fscanf(fp,"%d %d",&x,&y);
		Map.resize(x*y);
		while (i<x*y)
		{
			fscanf(fp, "%d", &Map[i]);
			i++;
		}
		fclose(fp);
		MapSize = {x*32,y*32};
		MapScreen = MakeScreen(MapSize.x,MapSize.y, true);
		SetDrawScreen(MapScreen);
		for (i = 0; i <y; i++)
		{
			for (int j=0;j<x;j++)
			{
				DrawRotaGraph(j * 32,i*32,1.0,0,bgImage[Map[j+i*x]-1],true);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
	}

	// BGM挿入
	lpSEMng.readMusic("BGM" , "sound/魔王魂改変戦闘用BGM(改).mp3");


	ObjList.emplace_back(new player(ScrCenter, { 32,32 }));
	MapPos = { MapSize.x/2-ScrCenter.x,ScrCenter.y};
}

GameScene::~GameScene()
{

}
