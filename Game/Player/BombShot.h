#pragma once
#include "../Projectile.h"
class Camera;
class BombShot :
	public Projectile
{
public:
	bool IsDead()const { return !isActive_; };
	BombShot(const Vector2f pos,const Vector2f vel, std::shared_ptr<Camera> camera);
	void Update()override;
	///<summary>
	///</summary>
	void Draw()override;
	void OnHit(CollisionInfo&, CollisionInfo&)override;
	Position2f Pos();
	Position2 Size();
private:
	float angle;
	~BombShot();
};

