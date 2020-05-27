#pragma once
#include "../../Obj/Obj.h"
#include"../../manager/SceneManage.h"
#include"../Enemy.h"
class wolf:
	public Obj
{
public:
	void UpDate() override;
	void Draw() override;
	wolf(double pos);
	~wolf();
};

