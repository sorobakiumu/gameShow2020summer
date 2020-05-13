
#pragma once
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
public:
	unique_Base Update(unique_Base own) override;			
	TitleScene();
	~TitleScene();
private:
	int bgImage;
};