#pragma once
#include "../../Obj/Obj.h"
#include"../../manager/SceneManage.h"
#include"../Enemy.h"
class burst:
	public Obj
{
public:
	void UpDate() override;
	void Draw() override;
	burst(double pos);
	~burst();
};

