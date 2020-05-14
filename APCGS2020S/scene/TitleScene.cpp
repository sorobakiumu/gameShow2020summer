
#include "TitleScene.h"
#include "DxLib.h"

unique_Base TitleScene::Update(unique_Base own)
{
	return std::move(own);
}

TitleScene::TitleScene()
{
	//bgImage = LoadGraph();
}

TitleScene::~TitleScene()
{

}
