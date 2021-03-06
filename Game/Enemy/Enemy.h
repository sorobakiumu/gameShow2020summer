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
	int life_ = 0;//敵の体力(0以下は死を意味する)
	bool isDeletable_ = false;	//リストから消していい(破棄していい)
	Vector2f velocity_; //現在の速度

	///自分のクローンを返す・・・が、これは子クラスのを呼び出す(純粋仮想関数)
	virtual Enemy* MakeClone() = 0;
	///プレイヤーを狙う
	virtual void AimPlayer();
public:
	Enemy(const std::shared_ptr<Player>& p, std::shared_ptr<Camera> camera);
	//virtual Enemy* MakeClone()=0;
	virtual ~Enemy() = default;
	/// <summary>
	/// 攻撃を受けた
	/// </summary>
	/// <param name="damage">ダメージ値</param>
	virtual void OnDamage(int damage) = 0;
	/// <summary>
	/// 死イベント
	/// </summary>
	virtual void OnDead() = 0;
	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;
	///座標アクセス
	virtual const Vector2f& GetPosition()const;
	virtual void SetPosition(const Vector2f& vel);
	///速度アクセス
	virtual const Vector2f& GetVelocity()const;
	virtual void SetVelocity(const Vector2f& vel);
	/// <summary>
	/// 死んでるかー？
	/// </summary>
	/// <returns>死んでる:true。生きてる:false</returns>
	virtual bool IsDead()const;
	/// <summary>
	/// 削除してOK？
	/// </summary>
	/// <returns>OK:true,NG:false</returns>
	virtual bool IsDeletable()const;
	virtual void OnHit(CollisionInfo& , CollisionInfo&)override;
};


