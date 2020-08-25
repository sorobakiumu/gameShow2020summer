#pragma once
#include "Collider.h"
#include "../../Geometry.h"
class CapsuleCollider :
	public Collider
{
private:
	Capsule capsule_;
public:
	CapsuleCollider(std::shared_ptr<Character> owner, Capsule c, const char* tag,bool isImmortal);
	bool IsHit(std::shared_ptr<Collider> col);
	Capsule& GetCapsule();
	void Draw();
	const Vector2f ActualPosition();
};

