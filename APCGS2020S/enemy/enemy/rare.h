#pragma once
#include "BaseEnemy.h"
class rare :
public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	rare();
	~rare();
};

