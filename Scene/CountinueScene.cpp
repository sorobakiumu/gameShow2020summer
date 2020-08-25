#include "CountinueScene.h"
#include "GameOverScene.h"
#include "../System/Input.h"
#include "DxLib.h"

using namespace std;

namespace {
	//constexpr unit32_t fadeouto_inteerval = 45;
	//constexpr unit32_t fadeouto_inteerval = 45;
	//constexpr unit32_t fadeouto_inteerval = 45;
	const int blink_interval_fast = 45;
	const int fadeouto_interval = 45;
	int blinkInterval_;
	int waitTimer_;
	int blinkTimer_ = 0;

	int titleH;
	int stertH;
}
CountinueScene::CountinueScene(SceneController& c) :Scene(c)
{
	updater_ = &CountinueScene::WaitUpdate;
	drawer_ = &CountinueScene::FadeInDraw;
	waitTimer_ = 45;
}
void CountinueScene::WaitUpdate(const Input& input)
{
	if (waitTimer_ <= 0) {
		if (input.IsTriggerd("OK")) {
			updater_ = &CountinueScene::FastBlinkUpdate;
			blinkInterval_ = blink_interval_fast;
			waitTimer_ = 30;
		}
	}
}
void CountinueScene::FastBlinkUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		updater_ = &CountinueScene::FadeoutUpdate;
		waitTimer_ = fadeouto_interval;
		drawer_ = &CountinueScene::FadeOutDraw;
	}
}
void CountinueScene::FadeoutUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		controller_.ChengeScene(new GameOverScene(controller_));
	}
}
void CountinueScene::NormalDraw()
{
	DrawGraph(0, 0, titleH, true);
	DrawGraph(100, 300, stertH, true);

	DrawString(100, 100, L"CountinueScene", 0xffffff);
}
void CountinueScene::FadeOutDraw()
{
	NormalDraw();
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - waitTimer_) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
void CountinueScene::FadeInDraw()
{
	NormalDraw();
	if (--waitTimer_ == 0) {
		drawer_ = &CountinueScene::NormalDraw;
	}
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - (fadeouto_interval - waitTimer_)) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
void CountinueScene::Update(const Input& input)
{
	blinkTimer_ = (blinkTimer_ + 1) % 600;
	(this->*updater_)(input);
}

void CountinueScene::Draw()
{
	(this->*drawer_)();
}
