#pragma once
#include "Enemy.h"
class EffectMng;
class Camera;
class Stage;
class Slasher :
	public Enemy
{
private:
	int flame = 0;
	Enemy* MakeClone() override;
	int animFrame_;

	using Func_t = void (Slasher::*)();

	void RunUpdate();
	void SlashUpdate();
	void JampUpdate();
	Func_t updater_;

	void RunDraw();
	void SlashDraw();
	Func_t drawer_;

	bool isDeletable_ = false;
	std::shared_ptr<Stage> stage_;
public:
	Slasher(const std::shared_ptr<Player>& p, std::shared_ptr<Camera> camera, std::shared_ptr<Stage> st);
/// <summary>
/// �U�����󂯂�
/// </summary>
/// <param name="damage">�_���[�W�l</param>
	void OnDamage(int damage);
	/// <summary>
	/// ���C�x���g
	/// </summary>
	void OnDead();
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	///���W�A�N�Z�X
	const Vector2f& GetPosition()const;
	void SetPosition(const Vector2f& vel);
	///���x�A�N�Z�X
	const Vector2f& GetVelocity()const;
	void SetVelocity(const Vector2f& vel);
	/// <summary>
	/// ����ł邩�[�H
	/// </summary>
	/// <returns>����ł�:true�B�����Ă�:false</returns>
	bool IsDead()const;
	/// <summary>
	/// �폜����OK�H
	/// </summary>
	/// <returns>OK:true,NG:false</returns>
	bool IsDeletable()const;
	///<summary>
	///����ɓ����������ǂ��Ȃ邩
	///</summary>
	void OnHit(CollisionInfo&, CollisionInfo&)override;
	std::shared_ptr<EffectMng> effectManager_;
};

