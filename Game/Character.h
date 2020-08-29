#pragma once
#include<memory>
#include "../Geometry.h"
class Input;
struct  CollisionInfo;
class Camera;
class Character
{
protected:
	std::shared_ptr<Camera> camera_;
	Vector2f pos_;
public:
	Character(std::shared_ptr<Camera> camera);

	///<summary>�L�����N�^�[�̍X�V���s��</summary>
	///<param name="input">����</param>
	///<memo>�v���C���[�ȊO�ɗv�͂Ȃ��p�����[�^�[�����ǕK�v�Ȃ��z�͖�������΂���</memo>
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual ~Character()=default;
	///<summary>�Փ˔���C�x���g</summary>
	///<param name="me">����</param>
	///<param name="another">����</param>
	virtual void OnHit(CollisionInfo& another,CollisionInfo& me)=0;
	Position2f Pos();
	Position2f GetPosition();
	Position2 Size() { return { 32,32 }; }
	std::shared_ptr<Camera> GetCamera();
};

