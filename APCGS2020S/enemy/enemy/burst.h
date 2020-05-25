#pragma once
#include "BaseEnemy.h"
class burst :
public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	burst();
	~burst();
};

