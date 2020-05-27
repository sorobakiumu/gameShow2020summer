
#include "TitleScene.h"
#include "DxLib.h"
#include "GameScene.h"
#include "../manager/SceneManage.h"
#include "../manager/ImageManage.h"


unique_Base TitleScene::Update(unique_Base own)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		return std::move(std::make_unique<GameScene>());
	}

	lpSceneMng.addDrawQue(std::make_tuple(lpSceneMng.ScreenCenter, 1.0, 0.0, tlImage, LAYER::UI, 999));

	return std::move(own);
}

TitleScene::TitleScene()
{

	tlImage = LoadGraph("image/ƒ^ƒCƒgƒ‹(‰¼).png", true);

}

TitleScene::~TitleScene()
{

}
