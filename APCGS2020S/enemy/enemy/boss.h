#pragma once
#include "BaseEnemy.h"
class boss :
public BaseEnemy
{
public:
	void UpDate(Vec2double pPos) override;
	void Draw() override;
	boss();
	~boss();
private:
	void pit(int num);
	Vec2double pitCnt[4];
};

