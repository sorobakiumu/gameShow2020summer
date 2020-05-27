#pragma once
#include "../../Obj/Obj.h"
#include"../../manager/SceneManage.h"
#include"../Enemy.h"
class rare :
	public Obj
{
public:
	void UpDate() override;
	void Draw() override;
	rare(double pos);
	~rare();
};

