#pragma once
#include"SceneController.h"

class Input;

//�V�[�����N���X
class Scene
{
	friend SceneController;
protected:
	SceneController& controller_;
	Scene() = default;
	Scene(SceneController&);
public:
	virtual void Update(const Input&) = 0;
	virtual void Draw() = 0;
	virtual ~Scene() = default;

};

