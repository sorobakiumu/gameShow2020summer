#pragma once
#include "Scene.h"
class GamePlaingScene;

class GameOverScene :
	public Scene
{
	friend GamePlaingScene;
private:
	void WaitUpdate(const Input&);
	void FastBlinkUpdate(const Input&);
	void FadeoutUpdate(const Input&);

	using UpdateFunction_t = void (GameOverScene::*)(const Input&);
	UpdateFunction_t updater_;

	void NormalDraw();
	void FadeOutDraw();
	void FadeInDraw();
	void (GameOverScene::* drawer_)();
public:
	GameOverScene(SceneController&);
	~GameOverScene() = default;
	void Update(const Input&)override;
	void Draw()override;
};