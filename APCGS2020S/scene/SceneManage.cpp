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

	// ���я���

	//SetWindowText("�G�i�h��");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);		// 640�~480�ޯāA65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);								// true.window false.�ٽ�ذ�

	if (DxLib_Init() == -1)								// DXײ���؂̏���������
	{
		// AST();
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);						// �`�����o�b�N�o�b�t�@�ɐݒ�

	return rtnFlag;
}