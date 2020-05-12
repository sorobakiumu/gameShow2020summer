#include "DxLib.h"

#include "SceneManage.h"

SceneManage* SceneManage::sInstance = nullptr;

SceneManage::SceneManage() :ScreenSize{ 640,480 }, ScreenCenter{ ScreenSize.x / 2,ScreenSize.y / 2 }
{

}

SceneManage::~SceneManage()
{
}

void SceneManage::Run()
{
	SysInit();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

	}

	return;
}

bool SceneManage::SysInit()
{
	bool rtnFlag = true;

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

	return rtnFlag;
}