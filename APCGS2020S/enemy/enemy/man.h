#pragma once
#include "../../Obj/Obj.h"
#include"../../manager/SceneManage.h"
#include"../Enemy.h"
class man :
	public Obj
{
public:
	void UpDate() override;
	void Draw() override;
	man();
	~man();
};

