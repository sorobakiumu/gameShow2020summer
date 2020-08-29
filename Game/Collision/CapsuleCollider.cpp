#include "CapsuleCollider.h"
#include "CircleCollider.h"
#include "../Character.h"
#include <algorithm>
#include<DxLib.h>
#include <assert.h>

using namespace std;

namespace {
	float Clamp(float value, float minVal = 0.0f, float maxVal = 1.0f){
		return min(max(value, minVal), maxVal);
	}
}
CapsuleCollider::CapsuleCollider(std::shared_ptr<Character> owner, Capsule c, const char* tag, bool isImmortal):Collider(owner,tag, isImmortal),capsule_(c)
{
}

bool CapsuleCollider::IsHit(std::shared_ptr<Collider> col)
{
	assert(col != nullptr);
	if (capsule_.vec.SQMagnitude() == 0)return false;
	auto ccol = dynamic_pointer_cast<CircleCollider>(col);
	if (ccol != nullptr) {
		Capsule capsule = { ActualPosition() ,capsule_.vec, capsule_.radius };
		Circle circle = { ccol->ActualPosition() ,ccol->GetCircle().radius };
		Vector2f vp = circle.center - capsule.start;
		float SQDist = (vp - capsule.vec * Clamp(vp.Dot(capsule.vec) /
			capsule.vec.SQMagnitude(), 0, 1)
			).SQMagnitude();
		float totalRadius = circle.radius + capsule.radius;
		return SQDist <= totalRadius * totalRadius;
	}
	return false;
}

Capsule& CapsuleCollider::GetCapsule()
{
	return capsule_;
}

void CapsuleCollider::Draw()
{
	Capsule capsule = { ActualPosition(),capsule_.vec,capsule_.radius };
	auto& spps = capsule.start;
	auto epps = capsule.start + capsule.vec;
	DrawCircle((int)spps.x, (int)spps.y, static_cast<int>(capsule.radius),0xffffff, false);

	auto v90 = capsule.vec;
	v90 = { -v90.y,v90.x };
	v90 = v90.Nomerize();
	v90.x *= capsule.radius;
	v90.y *= capsule.radius;
	auto p1 = spps + v90;
	auto p2 = epps + v90;
	auto p3 = epps - v90;
	auto p4 = spps - v90;

	DrawQuadrangleAA(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y, 0xffffff, false);
	DrawCircle((int)epps.x, (int)epps.y, static_cast<int>(capsule.radius), 0xffffff, false);
}

const Vector2f CapsuleCollider::ActualPosition()
{
	return capsule_.start + GetOwner()->GetCameraPos();
}
