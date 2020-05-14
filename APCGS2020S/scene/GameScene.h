#pragma once
#include <vector>
#include "BaseScene.h"
#include "../Obj/Obj.h"

class GameScene :
	public BaseScene
{
public:
	unique_Base Update(unique_Base own) override;			//�V�[�����A�X�V����B
	GameScene();
	~GameScene();
private:
	int bgImage;
	std::vector<SharedObj> ObjList;
};
