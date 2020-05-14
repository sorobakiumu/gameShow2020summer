#include <DxLib.h>
#include "GameScene.h"
#include "SceneManage.h"
#include"TitleScene.h"

unique_Base GameScene::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		return std::move(std::make_unique<TitleScene>());
	}
	lpSceneMng.addDrawQue(std::make_tuple(lpSceneMng.ScreenCenter,1.0,0.0,bgImage));
	return std::move(own);
}


GameScene::GameScene()
{
	bgImage = LoadGraph("image/game.png");
}

GameScene::~GameScene()
{

}
