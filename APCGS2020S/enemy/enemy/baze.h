#pragma once
#include "../../Obj/Obj.h"
#include"../../manager/SceneManage.h"
#include"../Enemy.h"
class baze:
public Obj
{
public:
	void UpDate() override;
	void Draw() override;
	baze();
	~baze();
};

