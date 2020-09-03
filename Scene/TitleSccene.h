#pragma once
#include "Scene.h"
#include "PauseScene.h"


class Scene;
class GameOverScene;
class PauseScene;
class TitleScene:public Scene
{
	friend SceneController;
	friend GameOverScene;
	friend PauseScene;
private:
	TitleScene(SceneController& c);
	void WaitUpdate(const Input&);
	void FastBlinkUpdate(const Input&);
	void FadeoutUpdate(const Input&);

	using UpdateFunction_t = void (TitleScene::*)(const Input&);
	UpdateFunction_t updater_;

	void NormalDraw();
	void FadeOutDraw();
	void FadeInDraw();
	void (TitleScene::* drawer_)();


public:
	void Update(const Input&)override;
	void Draw()override;
};