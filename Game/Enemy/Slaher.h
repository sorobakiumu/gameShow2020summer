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
/// 攻撃を受けた
/// </summary>
/// <param name="damage">ダメージ値</param>
	void OnDamage(int damage);
	/// <summary>
	/// 死イベント
	/// </summary>
	void OnDead();
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	///座標アクセス
	const Vector2f& GetPosition()const;
	void SetPosition(const Vector2f& vel);
	///速度アクセス
	const Vector2f& GetVelocity()const;
	void SetVelocity(const Vector2f& vel);
	/// <summary>
	/// 死んでるかー？
	/// </summary>
	/// <returns>死んでる:true。生きてる:false</returns>
	bool IsDead()const;
	/// <summary>
	/// 削除してOK？
	/// </summary>
	/// <returns>OK:true,NG:false</returns>
	bool IsDeletable()const;
	///<summary>
	///相手に当たった時どうなるか
	///</summary>
	void OnHit(CollisionInfo&, CollisionInfo&)override;
	std::shared_ptr<EffectMng> effectManager_;
};

