
#include "TitleScene.h"
#include "DxLib.h"
#include "GameScene.h"
#include "SceneManage.h"

unique_Base TitleScene::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::move(std::make_unique<GameScene>());
	}
	return std::move(own);
}

TitleScene::TitleScene()
{
	bgImage = 0/*LoadGraph()*/;
}

TitleScene::~TitleScene()
{

}
