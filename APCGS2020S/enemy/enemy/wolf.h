#pragma once
#include "BaseEnemy.h"
class wolf :
	public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw();
	wolf();
	~wolf();
};

