#pragma once
#include "BaseScene.h"
class GameScene :
	public BaseScene
{
public:
	unique_Base Update(unique_Base own) override;			//�V�[�����A�X�V����B
	GameScene();
	~GameScene();
private:
	int bgImage;
};
