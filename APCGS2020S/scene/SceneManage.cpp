#include "DxLib.h"
#include "TitleScene.h"
#include "SceneManage.h"

SceneManage* SceneManage::sInstance = nullptr;

void SceneManage::Draw()
{
	ClsDrawScreen();
	Vec2double pos;
	double size,angle;
	int image;
	for (auto dque : _drawList)
	{
		dque=std::tie(pos,size,angle,image);
		DrawRotaGraph(pos.x, pos.y,
			size, angle,
			image, true, true);
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
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
		Draw();
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