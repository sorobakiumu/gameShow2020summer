#pragma once
#include <memory>
#include"../Scene/Scene.h"
#include "Input.h"


class SceneController;
struct Size;
//�\�����ׂ���ʂ̏������B
class Viewport {
public:
	Size& GetSize() const;
};
class Application
{
private:
	Viewport viewport;
	std::shared_ptr<SceneController> _sceneContller;

	Application() = default;
	Application(const Application&) = delete;
	void operator = (const Application&) = delete;

	Input input;
public:
	//�X���O���g���C���X�^���X
	static Application& Instance() {
		static Application instance;
		return instance;
	}
	//������
	bool Initalaize();
	//����
	void Run();
	//�㏈��
	void Terminate();
	///<summary>
	///�A�v���P�[�V�������I������
	///</summary>
	void Exit();

	const Viewport& GetViewport()const;
};

