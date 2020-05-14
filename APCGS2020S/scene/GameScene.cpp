#include <DxLib.h>
#include "GameScene.h"
#include "SceneManage.h"
#include "TitleScene.h"

#include "../Obj/Gimmick/Lift.h"

unique_Base GameScene::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		return std::move(std::make_unique<TitleScene>());
	}
	for (auto obj : ObjList)
	{
		obj->UpDate();
	}
	lpSceneMng.addDrawQue(std::make_tuple(lpSceneMng.ScreenCenter,1.0,0.0,bgImage));
	return std::move(own);
}


GameScene::GameScene()
{
	bgImage = LoadGraph("image/game.png");
	ObjList.emplace_back(new Lift({ static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y)}, { 0,static_cast<double>(ScrCenter.y) }, { static_cast<double>(ScrSize.x),static_cast<double>(ScrCenter.y) },300));
}

GameScene::~GameScene()
{

}
