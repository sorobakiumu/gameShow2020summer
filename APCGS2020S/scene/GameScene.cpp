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
	for (auto obj : ObjList)
	{
		obj->UpDate();
		if (obj->GetID()==OBJ_ID::PLAYER)
		{
			plPos = obj->GetPos();
		}
	}
	MapPos = { (MapSize.x / 2) - plPos.x,ScrCenter.y+16.0};
	if (MapPos.x< -ScrCenter.x)
	{
		MapPos.x = -ScrCenter.x;
	}
	else if (MapPos.x > (MapSize.x- ScrSize.x - ScrCenter.x))
	{
		MapPos.x = MapSize.x-ScrSize.x-ScrCenter.x;
	}
	lpSceneMng.addDrawQue(std::make_tuple(MapPos,1.0,0.0,MapScreen));
	return std::move(own);
}


GameScene::GameScene()
{
	LoadDivGraph("image/tile.png",9,3,3,32,32,bgImage);
	//ObjList.emplace_back(new Lift({ static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y)}, { 0,static_cast<double>(ScrCenter.y) }, { static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) },300));
	ObjList.emplace_back(new player(ScrCenter, {0,0}));
	FILE* fp;
	fopen_s(&fp,"Data/test2.dat","rb");
 	if (fp != nullptr)
	{
		int x, y,i=0;
		std::vector<int> map;
		fscanf(fp,"%d %d",&x,&y);
		map.resize(x*y);
		while (i<x*y)
		{
			fscanf(fp, "%d", &map[i]);
			i++;
		}
		fclose(fp);
		MapSize = {x*32.0,y*32.0};
		MapScreen = MakeScreen(MapSize.x,MapSize.y, true);
		SetDrawScreen(MapScreen);
		for (i = 0; i <y; i++)
		{
			for (int j=0;j<x;j++)
			{
				DrawRotaGraph(j * 32,i*32,1.0,0,bgImage[map[j+i*x]-1],true);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
	}

}

GameScene::~GameScene()
{

}
