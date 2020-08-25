#include "Projectile.h"
#include "Player/Camera.h"

Projectile::Projectile(std::shared_ptr<Camera> camera):Character(camera)
{
}

bool Projectile::IsDead() const
{
	return !isActive_;
}

void Projectile::Update()
{
	pos_.x += vel_.x;
	pos_.y += vel_.y;
}

void Projectile::OnHit(CollisionInfo&, CollisionInfo&)
{
}
