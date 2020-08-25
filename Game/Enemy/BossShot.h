#pragma once
#include "../Projectile.h"
class BossShot :
	public Projectile
{
public:
	virtual void Update()override;
	virtual void Draw()override;
	void OnHit(CollisionInfo&, CollisionInfo&)override;
	BossShot (const Vector2f pos, const Vector2f vel, std::shared_ptr<Camera> camera);
private:
	float angle;
	int shotH[5];
	int frame_ = 0;
};

