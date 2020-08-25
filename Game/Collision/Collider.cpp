#include "Collider.h"
#include "../../Geometry.h"
#include "../Character.h"

Collider::Collider()
{
}

Collider::Collider(std::shared_ptr<Character> owner,const char* tag, bool isImmortal):owner_(owner),tag_(tag),isImmortal_(isImmortal)
{
}

const std::string& Collider::GetTag() const
{
	return tag_;
}

bool Collider::OwnerIsDead() const
{
	return owner_.expired();
}

bool Collider::IsDead() const
{
	return dead;
}


std::shared_ptr<Character> Collider::GetOwner()
{
	if (OwnerIsDead())
	{
		return nullptr;
	}
	else
	{
		return owner_.lock();
	}
}

void Collider::Suicide()
{
	if (isImmortal_)
		return;
	dead = true;
}
