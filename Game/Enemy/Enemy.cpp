#include "Enemy.h"
#include "../Player/Player.h"
#include"../../Geometry.h"
#include "../Player/Camera.h"
#include "../Character.h"

void Enemy::AimPlayer()
{
	velocity_.x = player_->GetPosition().x - pos_.x;
	velocity_.y = player_->GetPosition().y - pos_.y;
	velocity_.y = 0;
	velocity_=velocity_.Nomerize();
}

Enemy::Enemy(const std::shared_ptr<Player>& p, std::shared_ptr<Camera> camera):player_(p),Character(camera)
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}

const Vector2f& Enemy::GetPosition() const
{
	return pos_;
}

void Enemy::SetPosition(const Vector2f& vel)
{
	pos_ = vel;
}

const Vector2f& Enemy::GetVelocity() const
{
	return velocity_;
}

void Enemy::SetVelocity(const Vector2f& vel)
{
	velocity_ = vel;
}

bool Enemy::IsDead() const
{
	return life_<=0;
}

bool Enemy::IsDeletable() const
{
	return isDeletable_;
}

void Enemy::OnHit(CollisionInfo&, CollisionInfo&)
{
}

