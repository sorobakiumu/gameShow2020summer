#pragma once
#include <array>
#include "Boss.h"
class BossShot;
class GamePlaingScene;
class Asura :
	public Boss
{
private:
    struct EnergyBall{
        Vector2f pos;
        int frame;
    };
    std::array<EnergyBall, 4> enelgyBalls = {
        Vector2f(-128.0f,-50.0f),0,
        Vector2f(128.0f,-50.0f),150,
        Vector2f(-128.0f,50.0f),300,
        Vector2f(128.0f,50.0f),450
    };
    int ashuraH_[3] = {};
    int chargeH_[30];
    int frame_ = 0;
    int cnt;
    Enemy* MakeClone()override;
    using Update_t = void (Asura::*)();
    Update_t updater_;
    using Draw_t = void (Asura::*)();
    Draw_t drawer_;
 
    void InitializeUpdate();

    //登場演出状態 
    void EnteringUpdate();

    //通常状態 
    void NormalUpdate();

    //ダメージ状態 
    void DamageUpdate();

    //退場演出状態 
    void ExitingUpdate();

    //死 
    void DeadUpdate();

    //通常描画 
    void NormalDraw();
    void DamageDraw();
    void ExitingDraw();
    void DeadDraw();
    std::vector<Circle> circles_;

    std::vector<std::shared_ptr<BossShot>> bossShots_;
    void NomerizePush(Vector2f& vel, Position2f& pos);
    void Attack(Position2f& pos);
public:
    Asura(GamePlaingScene*);
    ~Asura() = default;

    void OnHit(CollisionInfo&, CollisionInfo&)override;

    /// <summary> 
    /// 攻撃を受けた 
    /// </summary> 
    /// <param name="damage">ダメージ値</param> 
    void OnDamage(int damage)override;

    /// <summary> 
    /// 死イベント 
    /// </summary> 
    void OnDead()override;

    /// <summary> 
    /// 更新 
    /// </summary> 
    void Update()override;
    /// <summary> 
    /// 描画 
    /// </summary> 
    void Draw()override;

};

