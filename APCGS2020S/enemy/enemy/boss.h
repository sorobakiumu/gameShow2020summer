#pragma once
#include "../../Obj/Obj.h"
#include"../../manager/SceneManage.h"
#include"../Enemy.h"
class boss :
	public Obj
{
public:
	void UpDate() override;
	void Draw() override;
	boss(double pos);
	~boss();
private:
	void pit(int num);
	Vec2double pitCnt[4];
};

