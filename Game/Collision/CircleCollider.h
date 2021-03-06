#pragma once
#include "Collider.h"
#include "../../Geometry.h"
///<summry>
///円の当たり判定クラス
///</summry>
class CircleCollider :
	public Collider
{
private:
    Circle circle_;///<判定に使う円 
    
public:
    /// <summary> 
    /// 何もなければ{0,0},0 「円のコライダー」 
    /// </summary> 
    CircleCollider() :circle_({ 0,0 }, 0){}

    /// <summary> 
    /// 円情報から円衝突判定を作る 
    /// </summary> 
    /// <param name="c">円情報</param> 
    CircleCollider(std::shared_ptr<Character> owner, const char* tag);

    /// <summary> 
    /// 中心と半径から円衝突情報を作る 
    /// </summary> 
    /// <param name="p">中心</param> 
    /// <param name="r">半径</param> 
    CircleCollider(std::shared_ptr<Character> owner, const char* tag, Circle c);

    bool IsHit(std::shared_ptr<Collider> col)override;

    const Position2f ActualPosition();
    void Draw();

    const Circle& GetCircle()const;
};

