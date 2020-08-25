#pragma once
#include "Scene.h"
#include "GamePlaingScene.h"
#include"SceneController.h"
#include<sstream>
#include"../Geometry.h"
#include<vector>
#include<string>
#include <functional>

struct MenuItem
{
	std::wstring menuText;
	Vector2 pos;
	bool isActive = false;
	std::function<void(void)> func;
	MenuItem(const wchar_t* str, const Vector2& p, std::function<void(void)> f) :
		menuText(str),
		func(f),
		pos(p) {}
};

class GamePlaingScene;
class PauseScene :
	public Scene
{
	friend GamePlaingScene;
	void NomalDraw();
	using DrawFunction_t = void (PauseScene::*)(const Input&);
	std::vector<MenuItem> menuItems_;
public:
	PauseScene(SceneController&);
	virtual void Update(const Input&) override;
	virtual void Draw() override;
};


