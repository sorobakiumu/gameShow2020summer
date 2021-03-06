#pragma once
#include <memory>
#include <list>
#include "../../Geometry.h"
class Camera;
class Enemy;
/// <summary>
/// 敵発生器基底クラス
/// </summary>
class EnemyManager;
class Spawner
{
protected:
	Position2f pos_;//画面内にスポーナーがあるかどうかの判定が必要なため座標がいる
	std::unique_ptr<Enemy> prototype_;//プロトタイプ
	std::shared_ptr<EnemyManager>& enemyManager;
	std::shared_ptr<Camera> camera_;
	virtual Enemy* CreatCloan()final;

public:
	Spawner(const Position2f& pos, Enemy* prototype, std::shared_ptr<EnemyManager>& em, std::shared_ptr<Camera> c);
	virtual ~Spawner() = default;
	/// <summary>
	/// 生成時にリストに放り込むが同時にシェアポインタも返す
	/// </summary>
	/// <returns></returns>
//	virtual std::shared_ptr<Enemy> Spawn() = 0;
	/// <summary>
	/// 時間ごとの発生などが必要なため毎フレーム更新を行う
	/// </summary>
	virtual void Update() = 0;
};
