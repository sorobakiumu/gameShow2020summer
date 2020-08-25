#pragma once
#include<memory>
#include <deque>
#include <functional>

class Scene;
class Input;
class Applivation;
class SceneController
{
private:

	std::deque<std::shared_ptr<Scene>> scene_;
	std::function<void(void)> postDrawExecuter_;
public:
	SceneController();
	///�V�[�����V�[���X�^�b�N�̓��ɓ����
	void pushScene(Scene*);

	//�V�[���X�^�b�N�̐擪���폜����
	void PopScene();

	//�V�[���X�^�b�N����x�N���A���Ă���w��̃V�[���Ɉړ�����
	//�؂�ւ���̃V�[���I�u�W�F�N�g
	//�O�̃V�[���͌ďo����ɍ폜����邽�߂��̊֐��̌Ăяo����ɏ������s���Ă͂Ȃ�Ȃ�
	void CleneChangeScene(Scene*);

	//�V�[����؂�ւ���
	//�؂�ւ���̃V�[���I�u�W�F�N�g
	//�O�̃V�[���͌ďo����ɍ폜����邽�߂��̊֐��̌Ăяo����ɏ������s���Ă͂Ȃ�Ȃ�
	void ChengeScene(Scene*);

	//�����Ă���퓬�V�[���̃A�b�v�f�[�g���Ă�
	void Update(const Input&);

	//�����Ă���V�[�����ׂĂ�`�悷��
	void Draw();
	void ClearScene();
	void PushScene(Scene* scene);

};

