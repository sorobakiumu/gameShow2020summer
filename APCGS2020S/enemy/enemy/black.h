#pragma once
#include "BaseEnemy.h"
class black:
public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	black();
	~black();
};

