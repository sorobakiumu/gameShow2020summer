#pragma once
#include "BaseEnemy.h"
class baze:
public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	baze();
	~baze();
};

