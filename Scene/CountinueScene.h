#pragma once
#include "Scene.h"
class GamePlaingScene;
class CountinueScene :
	public Scene
{
	friend GamePlaingScene;
private:
	CountinueScene(SceneController&);
	void WaitUpdate(const Input&);
	void FastBlinkUpdate(const Input&);
	void FadeoutUpdate(const Input&);

	using UpdateFunction_t = void (CountinueScene::*)(const Input&);
	UpdateFunction_t updater_;

	void NormalDraw();
	void FadeOutDraw();
	void FadeInDraw();
	void (CountinueScene::* drawer_)();
public:
	~CountinueScene() = default;
	void Update(const Input&)override;
	void Draw()override;
};