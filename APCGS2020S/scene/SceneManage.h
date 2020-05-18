#pragma once
#include <Windows.h>
#include<vector>
#include <tuple>
#include "../Common/Vector2.h"
#include "BaseScene.h"
#include "LAYER.h"

using DRAW_QUE = std::tuple<Vec2double, double, double, int,LAYER,int>;		//座標、サイズ（倍率）、角度、ハンドル、レイヤー,Zオーダー
#define lpSceneMng SceneManage::GetInstance()
#define ScrSize lpSceneMng.ScreenSize
#define ScrCenter lpSceneMng.ScreenCenter

class SceneManage
{
public:
	static SceneManage& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneManage();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}

	const Vec2Int ScreenSize;
	Vec2double ScreenCenter;

	//描画したいものをキューに追加する
	void addDrawQue(DRAW_QUE dque);

	int FrmCnt() { return frmCnt; }

	void Run();
private:
	static SceneManage* sInstance;
	unique_Base _activeScene;		//<BaseScene>を、使っているのがいなくなったら消える

	std::vector<DRAW_QUE> _drawList;	//描画したいリスト
	void Draw();

	int frmCnt;

	SceneManage();
	~SceneManage();

	bool SysInit();

};