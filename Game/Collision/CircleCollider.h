#pragma once
#include "Collider.h"
#include "../../Geometry.h"
///<summry>
///‰~‚Ì“–‚½‚è”»’èƒNƒ‰ƒX
///</summry>
class CircleCollider :
	public Collider
{
private:
    Circle circle_;///<”»’è‚Ég‚¤‰~ 
    
public:
    /// <summary> 
    /// ‰½‚à‚È‚¯‚ê‚Î{0,0},0 u‰~‚ÌƒRƒ‰ƒCƒ_[v 
    /// </summary> 
    CircleCollider() :circle_({ 0,0 }, 0){}

    /// <summary> 
    /// ‰~î•ñ‚©‚ç‰~Õ“Ë”»’è‚ğì‚é 
    /// </summary> 
    /// <param name="c">‰~î•ñ</param> 
    CircleCollider(std::shared_ptr<Character> owner, const char* tag);

    /// <summary> 
    /// ’†S‚Æ”¼Œa‚©‚ç‰~Õ“Ëî•ñ‚ğì‚é 
    /// </summary> 
    /// <param name="p">’†S</param> 
    /// <param name="r">”¼Œa</param> 
    CircleCollider(std::shared_ptr<Character> owner, const char* tag, Circle c);

    bool IsHit(std::shared_ptr<Collider> col)override;

    const Position2f ActualPosition();
    void Draw();

    const Circle& GetCircle()const;
};

