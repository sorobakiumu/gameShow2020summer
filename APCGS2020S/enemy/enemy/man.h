#pragma once
#include "BaseEnemy.h"
class man :
public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	man();
	~man();
};

