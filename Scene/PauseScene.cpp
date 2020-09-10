#include "PauseScene.h"
#include "DxLib.h"
#include "../System/Input.h"
#include "../Geometry.h"
#include "TitleSccene.h"
#include"../System/Application.h"
#include "keyconfig.h"

namespace {
	int menueSize;
	Rect rec = { { 300,300 } , {300, 200} };
	const int menueSizeMax = rec.size.h;
	int indicatorH_ ;
	int indicator_w;
	constexpr int posetitle_y = 32;//ポーズタイトルのY
	constexpr int menubase_y = 96;//メニュー一番上のY
	constexpr int menubase_x = 64;//メニューの左のY
	constexpr int menu_y_interval = 48;//メニューの字間
	constexpr int indicator_x = 32;//indicatorのｘ
	const wchar_t pause_title[] =L"PauseMenu";
	int curentSelectNo_;
}
void PauseScene::NomalDraw()
{
	DeleteGraph(indicatorH_);
}

PauseScene::PauseScene(SceneController& c) :Scene(c)
{
	menueSize = 0;
	menuItems_.emplace_back(L"ゲームに戻る", Position2(menubase_x, menubase_y + menu_y_interval), [this]() {controller_.PopScene(); });
//	menuItems_.emplace_back(L"タイトルに戻る", Position2(menubase_x, menubase_y+ menu_y_interval*2), [this]() {controller_.CleneChangeScene(new TitleScene(controller_));});
	menuItems_.emplace_back(L"ゲーム終了", Position2(menubase_x, menubase_y + menu_y_interval * 3), []() { Application::Instance().Exit(); });
	menuItems_.emplace_back(L"キーコンフィグ", Position2(menubase_x, menubase_y + menu_y_interval * 4), [this]() {controller_.PushScene(new keyconfig(controller_, { 300,20 })); });
	curentSelectNo_ = 0;
	indicatorH_ = LoadGraph(L"image/UI/indicator.png");

}


void PauseScene::Update(const Input& input)
{

	menuItems_[curentSelectNo_].isActive = true;


	if (menueSize < menueSizeMax) {
		menueSize += 10;
		return;
	}
	for (unsigned int i = 0; i < menuItems_.size(); i++)
	{
		menuItems_[i].isActive = false;
	}
	GetGraphSize(indicatorH_, &indicator_w,nullptr);
	if (input.IsTriggerd("down")) {
		curentSelectNo_ = (curentSelectNo_ + 1) % menuItems_.size();
	}
	if (input.IsTriggerd("up")) {
		curentSelectNo_ = (curentSelectNo_ - 1 + menuItems_.size()) % menuItems_.size();
	}
	menuItems_[curentSelectNo_].isActive = true;

	auto selecticItem = menuItems_[curentSelectNo_];
	if (input.IsTriggerd("OK")) {
		selecticItem.func();
	}
	else if (input.IsTriggerd("pause")) {
		controller_.PopScene();
	}
}



void PauseScene::Draw()
{

	SetDrawBlendMode(DX_BLENDMODE_MULA,128);
	DrawBox(rec.pos.x, rec.pos.y - menueSize, rec.pos.x+ rec.size.w, rec.pos.y  +menueSize, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(rec.pos.x, rec.pos.y - menueSize, rec.pos.x + rec.size.w, rec.pos.y  +menueSize, 0xffffff, false);
	if (menueSize < menueSizeMax) {
		return;
	}
	int titleW=GetDrawStringWidth(pause_title,wcslen(pause_title));
	DrawString((rec.pos.x+titleW), (rec.pos.y+ posetitle_y)/2, pause_title,0xffffff);

	for (auto& m : menuItems_) {
		uint32_t col = m.isActive ? 0xffffff : 0xff0000;
		int offset = 32;
		int temp_x = m.pos.x;
		if (m.isActive) {
			temp_x += 32;
		}

		DrawString((rec.pos.x +temp_x), (rec.pos.y + m.pos.y)/2, m.menuText.c_str(), col);
	}
	auto& indPos = menuItems_[curentSelectNo_].pos;

	DrawGraph(rec.pos.x+indPos.x- indicator_x, (rec.pos.y + indPos.y) / 2,indicatorH_,true);
}
