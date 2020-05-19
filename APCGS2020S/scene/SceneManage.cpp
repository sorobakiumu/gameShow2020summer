#include "DxLib.h"
#include "TitleScene.h"
#include "SceneManage.h"
#include "algorithm"
#include "../enemy/Enemy.h"

SceneManage* SceneManage::sInstance = nullptr;

void SceneManage::Draw()
{
	ClsDrawScreen();

	std::sort(_drawList.begin(), _drawList.end(), [](DRAW_QUE dQa,DRAW_QUE dQb)
		{
			return std::tie(std::get <4>(dQa),std::get <5>(dQa))<std::tie(std::get <4>(dQb), std::get <5>(dQb));
		});




  	Vec2double pos;
	double size, angle;
	int image;
	LAYER layer;
	int tmpPosX;
	for (auto dque : _drawList)
	{
		std::tie(pos, size, angle, image,layer,std::ignore)=dque;
		if (layer==LAYER::PLAYER)
		{
			tmpPosX = pos.x - ScreenCenter.x;
			pos.x = ScreenCenter.x;
			for (auto dque : _drawList)
			{
				std::tie(pos, size, angle, image, layer, std::ignore) = dque;
				if (layer == LAYER::ENEMY||layer==LAYER::MAP)
				{
					pos.x -= tmpPosX;
				}
			}
		}
	}
	for (auto dque : _drawList)
	{
		std::tie(pos, size, angle, image, layer, std::ignore) = dque;
		DrawRotaGraph(pos.x, pos.y,
			size, angle,
			image, true, false);
	}
	ScreenFlip();
}

SceneManage::SceneManage() :ScreenSize{ 640,480 }, ScreenCenter{ ScreenSize.x / 2,ScreenSize.y / 2 }
{

}

SceneManage::~SceneManage()
{
}

void SceneManage::addDrawQue(DRAW_QUE dque)
{
	_drawList.emplace_back(dque);
}

void SceneManage::Run()
{
	SysInit();
	_activeScene = std::make_unique<TitleScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();
		frmCnt++;
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
		Draw();
	}

	return;
}

bool SceneManage::SysInit()
{
	bool rtnFlag = true;

	Enemy::initFlag = true;

	// ｼｽﾃﾑ処理

	//SetWindowText("エナドリ");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);		// 640×480ﾄﾞｯﾄ、65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);								// true.window false.ﾌﾙｽｸﾘｰﾝ

	if (DxLib_Init() == -1)								// DXﾗｲﾌﾞﾗﾘの初期化処理
	{
		// AST();
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);						// 描画先をバックバッファに設定

	frmCnt = 0;

	return rtnFlag;
}