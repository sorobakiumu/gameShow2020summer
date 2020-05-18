#include <DxLib.h>
#include <vector>
#include "GameScene.h"
#include "SceneManage.h"
#include "TitleScene.h"

#include "../Obj/Gimmick/Lift.h"
#include "../player/player.h"

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
			plPos = obj->GetPos();
			FuncCheckHit()(Cnt,this);		// ObjListの何番目かとゲームシーンのポインタを渡す
		}
		Cnt++;
	}
	if (ScrCenter.x-5<=plPos.x&&plPos.x<=ScrCenter.x+5)
	{
		MapPos.x = MapPos.x-(plPos.x-plPosOld.x);
	}


	plPosOld = plPos;
	if (MapPos.x< -ScrCenter.x)
	{
		MapPos.x = -ScrCenter.x;
	}
	else if (MapPos.x > (MapSize.x - ScrSize.x - ScrCenter.x))
	{
		MapPos.x = MapSize.x-ScrSize.x-ScrCenter.x;
	}
	else if(MapPos.x>-ScrCenter.x&&MapPos.x< (MapSize.x - ScrSize.x - ScrCenter.x))
	{
		for (auto obj : ObjList)
		{
			if (obj->GetID() == OBJ_ID::PLAYER)
			{
				obj->SetPos(ScrCenter);
				plPosOld = ScrCenter;
			}
		}

	}

	lpSceneMng.addDrawQue(std::make_tuple(MapPos,1.0,0.0,MapScreen,LAYER::MAP,0));

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

	return std::move(own);
}


GameScene::GameScene()
{
	MapScreen = 0;
	LoadDivGraph("image/tile.png", 9, 3, 3, 32, 32, bgImage);
	ObjList.emplace_back(new Lift({ static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, { 0,static_cast<double>(ScrCenter.y) }, { static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) }, 300));
	ObjList.emplace_back(new player(ScrCenter, { 32,32 }));

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
				DrawRotaGraph(j * 32,i*32,1.0,0,bgImage[Map[j+i*x]],true);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
	}
	MapPos = { MapSize.x/2-ScrCenter.x,ScrCenter.y};
}

GameScene::~GameScene()
{

}
