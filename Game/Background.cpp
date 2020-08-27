#include "Background.h"
#include "DxLib.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

Background::Background(std::shared_ptr<Camera>& camera):camera_(camera)
{
	bgH_.resize(11);
	int skipno[2] = { 4,7 };
	int no = 9;
	for (unsigned int i = 0; i < bgH_.size(); ++i) {
		wstringstream wss;
		wss << L"image/BG/Layer_";
		wss << setw(4) << setfill(L'0') << i << "_";
		if (count(begin(skipno), end(skipno), i) > 0) {
			wss << "Lights";
		}
		else {
			wss << no;
			--no;
		}
		wss << ".png";
		bgH_[bgH_.size() - 1 - i] = LoadGraph(wss.str().c_str());
	}
	frmCnt_ = 0;
	for (auto i=0;i<11;i++)
	{
		screen[i].screen = MakeScreen(800, 600,true);
		screen[i].pos_ = Position2f(0, 0);
	}
	for (auto i = 0; i < 11; i++)
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

void Background::Draw()
{
	for (unsigned int i = 0; i < bgH_.size(); i++)
	{
		SetDrawScreen(screen[i].screen);
		ClsDrawScreen();
		DrawExtendGraph(0, 0, 800, 600, bgH_[i], true);
		SetDrawScreen(screenNext[i].screen);
		ClsDrawScreen();
		DrawExtendGraph(0, 0, 800, 600, bgH_[i], true);
	}
	oldCameraPos_x = cameraPos_x;
	cameraPos_x = camera_->GetPosition().x;

	auto checkPos_x = oldCameraPos_x - cameraPos_x;

	auto pvel = checkPos_x /10;
	
	SetDrawScreen(DX_SCREEN_BACK);
	for (auto i=0;i < 11;i++)
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

