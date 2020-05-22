#include "DxLib.h"
#include "../scene/TitleScene.h"
#include "SceneManage.h"
#include "algorithm"
#include "../enemy/Enemy.h"
#include "ImageManage.h"

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
			if (pos.x < ScreenCenter.x )
			{
				tmpPosX = 0;
			}
			else if (pos.x > MapSize.x - ScreenCenter.x)
			{
				tmpPosX = MapSize.x-ScreenSize.x;
			}

			for (auto dque : _drawList)
			{
				std::tie(pos, size, angle, image, layer, std::ignore) = dque;
				if (layer == LAYER::ENEMY||layer==LAYER::MAP)
				{
					pos.x -= tmpPosX;
				}
				else if(layer == LAYER::PLAYER && pos.x>=ScreenCenter.x && pos.x<=MapSize.x-ScreenCenter.x)
				{
					pos.x = ScreenCenter.x;
				}
				else if (layer == LAYER::PLAYER && pos.x > MapSize.x - ScreenCenter.x)
				{
					pos.x = pos.x - static_cast<double>(MapSize.x - ScreenSize.x);
				}
				DrawRotaGraph(pos.x, pos.y,size, angle,image, true, false);
			}
		}
	}
	ScreenFlip();
}

SceneManage::SceneManage() :ScreenSize{ 640,480 }, ScreenCenter{ ScreenSize.x / 2,ScreenSize.y / 2 }, frmCnt{0}
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

	// ���ى�ʓǂݍ���
	lpImageMng.GetID("�^�C�g��" , "�^�C�g��(��).png");

	frmCnt = 0;

	return rtnFlag;
}