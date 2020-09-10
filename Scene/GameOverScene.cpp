#include "GameOverScene.h"
#include "TitleSccene.h"
#include "../System/Input.h"
#include "DxLib.h"
#include "../System/Application.h"


using namespace std;

namespace {
	const int blink_interval_fast = 45;
	const int fadeouto_interval = 45;
	int blinkInterval_;
	int waitTimer_;
	int blinkTimer_ = 0;

	int gameoverH;
	int stertH;
	int gameoverTextH;
}

GameOverScene::GameOverScene(SceneController& c) :Scene(c)
{
	updater_ = &GameOverScene::WaitUpdate;
	drawer_ = &GameOverScene::FadeInDraw;

	gameoverH = LoadGraph(L"image/BG/Title.png");
	gameoverTextH = LoadGraph(L"image/UI/gameoverText.png");
	waitTimer_ = 45;
}

void GameOverScene::WaitUpdate(const Input& input)
{
	if (waitTimer_ <= 0) {
		if (input.IsTriggerd("OK")) {
			updater_ = &GameOverScene::FastBlinkUpdate;
			blinkInterval_ = blink_interval_fast;
			waitTimer_ = 30;
		}
	}
}

void GameOverScene::FastBlinkUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		updater_ = &GameOverScene::FadeoutUpdate;
		waitTimer_ = fadeouto_interval;
		drawer_ = &GameOverScene::FadeOutDraw;
	}
}

void GameOverScene::FadeoutUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		controller_.ChengeScene(new TitleScene(controller_));
	}
}

void GameOverScene::NormalDraw()
{
	DrawString(100, 100, L"GamePlaingScene", 0xffffff);
	Size vsize = Application::Instance().GetViewport().GetSize();
	DrawExtendGraph(0, 0, 800, 600, gameoverH, true);
	DrawRotaGraph(vsize.w / 2, vsize.h * 1 / 4, 1.5f, 0.0f, gameoverTextH, true);
	if (blinkTimer_ % 100 / 10 < 6)
		DrawRotaGraph(vsize.w / 2, vsize.h * 3 / 4, 1.0f, 0.0f, stertH, true);
}

void GameOverScene::FadeOutDraw()
{
	NormalDraw();
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - waitTimer_) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GameOverScene::FadeInDraw()
{
	NormalDraw();
	if (--waitTimer_ == 0) {
		drawer_ = &GameOverScene::NormalDraw;
	}
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - (fadeouto_interval - waitTimer_)) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GameOverScene::Update(const Input& input)
{
	blinkTimer_ = (blinkTimer_ + 1) % 600;
	(this->*updater_)(input);
	if (input.IsTriggerd("OK"))
	{
		controller_.ChengeScene(new TitleScene(controller_));
	}
}

void GameOverScene::Draw()
{
	(this->*drawer_)();
}
