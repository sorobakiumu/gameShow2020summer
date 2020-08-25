#pragma once
#include "Enemy.h"
#include "../../Scene/GamePlaingScene.h"
class Boss :
	public Enemy
{
protected:
	GamePlaingScene* gameScene;
public:
	Boss(GamePlaingScene* gm);
};

