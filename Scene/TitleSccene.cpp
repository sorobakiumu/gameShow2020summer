#include "TitleSccene.h"
#include"SceneController.h"
#include "DxLib.h"
#include "GamePlaingScene.h"
#include "../System/Input.h"
#include "../Geometry.h"
#include"../System/Application.h"

using namespace std;

namespace {

	const int blink_interval_fast = 45;
	const int fadeouto_interval = 45;
	int blinkInterval_;
	int waitTimer_;
	int blinkTimer_;

	int titleH;
	int stertH;
	int titletextH;
}


TitleScene::TitleScene(SceneController& c) :Scene(c) {
	updater_ = &TitleScene::WaitUpdate;
	drawer_ = &TitleScene::FadeInDraw;
	waitTimer_ = 45;
	blinkTimer_ = 0;

	titleH = LoadGraph(L"image/BG/Title.png");
	stertH = LoadGraph(L"image/UI/pressstart.png");
	titletextH = LoadGraph(L"image/UI/titletext.png");
	selectSound = LoadSoundMem(L"sound/select.mp3");
	ChangeVolumeSoundMem(200, selectSound);
}

void TitleScene::WaitUpdate(const Input& input)
{
	if (waitTimer_ <= 0) {
		if (input.IsTriggerd("OK")) {
			PlaySoundMem(selectSound, DX_PLAYTYPE_BACK, TRUE);
			updater_ = &TitleScene::FastBlinkUpdate;
			blinkInterval_ = blink_interval_fast;

			waitTimer_ = 30;
		}
	}
}

void TitleScene::FastBlinkUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		updater_ = &TitleScene::FadeoutUpdate;
		waitTimer_ = fadeouto_interval;
		drawer_ = &TitleScene::FadeOutDraw;
	}
}

void TitleScene::FadeoutUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		controller_.ChengeScene(new GamePlaingScene(controller_));
	}
}

void TitleScene::NormalDraw()
{	
	Size vsize = Application::Instance().GetViewport().GetSize();
	DrawExtendGraph(0, 0, 800, 600, titleH, true);
	DrawRotaGraph(vsize.w / 2, vsize.h * 1 / 4, 1.5f, 0.0f, titletextH, true);
	if(blinkTimer_%100/10<6)
		DrawRotaGraph(vsize.w / 2, vsize.h *3/4, 0.7f, 0.0f, stertH, true);

}

void TitleScene::FadeOutDraw()
{
	Size vpSize = Application::Instance().GetViewport().GetSize(); 
	NormalDraw();
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - waitTimer_) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, vpSize.w, vpSize.h, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
void TitleScene::FadeInDraw()
{
	NormalDraw();
	if (--waitTimer_ == 0) {
		drawer_ = &TitleScene::NormalDraw;
	}
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval -(fadeouto_interval - waitTimer_)) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleScene::Update(const Input& input)
{
	blinkTimer_ = (blinkTimer_ + 1) % 600;
	(this->*updater_)(input);
}

void TitleScene::Draw()
{
	(this->*drawer_)();
}

