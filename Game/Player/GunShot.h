#pragma once
#include "../Projectile.h"
class GunShot :
	public Projectile
{
public:
	bool IsDead()const { return !isActive_; };
	GunShot(const Vector2f pos, const Vector2f vel, std::shared_ptr<Camera> camera);
	void Update()override;
	///<summary>
	///</summary>
	void Draw()override;
	void OnHit(CollisionInfo&, CollisionInfo&)override;
	Position2 Size;
private:
	float angle;
	~GunShot();

	int bulletH = -1;
};

