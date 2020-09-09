#include "Background.h"
#include "DxLib.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

Background::Background(std::shared_ptr<Camera>& camera):camera_(camera)
{
	bgH_.resize(3);
	for (unsigned int i = 0; i < bgH_.size(); ++i) {
		wstringstream wss;
		wss << L"image/BG/background_";
		wss << i ;
		wss << ".png";
		bgH_[i] = LoadGraph(wss.str().c_str());
	}
	frmCnt_ = 0;
	for (auto i=0;i<3;i++)
	{
		screen[i].screen = MakeScreen(800, 600,true);
		screen[i].pos_ = Position2f(0, 0);
	}
	for (auto i = 0; i < 3; i++)
	{
		screenNext[i].screen = MakeScreen(800, 600,true);
		screenNext[i].pos_ = Position2f(800, 0);
	}
}

Background::~Background()
{
	for (auto& bg : bgH_) {
	DeleteGraph(bg);
	}
}

void Background::Update()
{
	frmCnt_++;
}

void Background::Draw(bool flag)
{
	for (unsigned int i = 0; i < bgH_.size(); i++)
	{
		SetDrawScreen(screen[i].screen);
		ClsDrawScreen();
		if (flag) {
			SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
		}
		DrawExtendGraph(0, 0, 800, 600, bgH_[i], true);
		if (flag) {
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		SetDrawScreen(screenNext[i].screen);
		ClsDrawScreen();
		if (flag) {
			SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
		}
		DrawExtendGraph(0, 0, 800, 600, bgH_[i], true);
		if (flag) {
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	oldCameraPos_x = cameraPos_x;
	cameraPos_x = camera_->GetPosition().x;

	auto checkPos_x = oldCameraPos_x - cameraPos_x;

	auto pvel = checkPos_x /10;
	
	SetDrawScreen(DX_SCREEN_BACK);
	for (auto i=0;i < 3;i++)
	{
		if (screenNext[i].pos_.x + pvel * (i + 1) < 0) {
			screen[i].pos_.x = 0;
			screenNext[i].pos_.x = 800;
		}
		if (screen[i].pos_.x + pvel * (i + 1) > 0) {
			screen[i].pos_.x = -800;
			screenNext[i].pos_.x = 0;
		}
		screen[i].pos_.x += pvel * (i + 1);
		DrawGraph(screen[i].pos_.x, 0, screen[i].screen, true);

		screenNext[i].pos_.x = screen[i].pos_.x+800;
		DrawGraph(screenNext[i].pos_.x, 0, screenNext[i].screen, true);
	}
}

