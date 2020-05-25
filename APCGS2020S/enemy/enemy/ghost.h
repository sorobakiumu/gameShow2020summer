#pragma once
#include "BaseEnemy.h"
class ghost :
	public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	ghost();
	~ghost();
};

