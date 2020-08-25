#pragma once
#include "../Character.h"
class Player;
class Spawner;
class Camera;
class Enemy :
	public Character
{
	friend Spawner;
protected:
	const std::shared_ptr<Player>& player_;
	int life_ = 0;//�G�̗̑�(0�ȉ��͎����Ӗ�����)
	bool isDeletable_ = false;	//���X�g��������Ă���(�j�����Ă���)
	Vector2f velocity_; //���݂̑��x

	///�����̃N���[����Ԃ��E�E�E���A����͎q�N���X�̂��Ăяo��(�������z�֐�)
	virtual Enemy* MakeClone() = 0;
	///�v���C���[��_��
	virtual void AimPlayer();
public:
	Enemy(const std::shared_ptr<Player>& p, std::shared_ptr<Camera> camera);
	//virtual Enemy* MakeClone()=0;
	virtual ~Enemy() = default;
	/// <summary>
	/// �U�����󂯂�
	/// </summary>
	/// <param name="damage">�_���[�W�l</param>
	virtual void OnDamage(int damage) = 0;
	/// <summary>
	/// ���C�x���g
	/// </summary>
	virtual void OnDead() = 0;
	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() = 0;
	///���W�A�N�Z�X
	virtual const Vector2f& GetPosition()const;
	virtual void SetPosition(const Vector2f& vel);
	///���x�A�N�Z�X
	virtual const Vector2f& GetVelocity()const;
	virtual void SetVelocity(const Vector2f& vel);
	/// <summary>
	/// ����ł邩�[�H
	/// </summary>
	/// <returns>����ł�:true�B�����Ă�:false</returns>
	virtual bool IsDead()const;
	/// <summary>
	/// �폜����OK�H
	/// </summary>
	/// <returns>OK:true,NG:false</returns>
	virtual bool IsDeletable()const;
	virtual void OnHit(CollisionInfo& , CollisionInfo&)override;
};


