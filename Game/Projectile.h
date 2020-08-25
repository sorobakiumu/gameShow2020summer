#pragma once
#include "Character.h"

class Camera;
class Projectile:public Character
{
protected:
	std::shared_ptr<Camera> camera;
	Vector2f vel_;
	bool isActive_ = false;
public:
	Projectile(std::shared_ptr<Camera> camera);
	///<summary>
	///ˆê‰ž‚±‚±‚ÅŽÀ‘•‚·‚é
	///</summary>
	bool IsDead()const;

	virtual void Update()override;
	///<summary>
	///</summary>
	virtual void Draw() = 0;
	void OnHit(CollisionInfo&, CollisionInfo&)override;
};

