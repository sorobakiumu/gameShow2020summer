#include "CircleCollider.h"
#include "../Character.h"
#include "Collider.h"
#include <DxLib.h>
#include <assert.h>
#include "../Player/Camera.h"

//CircleCollider::CircleCollider()
//{
//}

CircleCollider::CircleCollider(std::shared_ptr<Character> owner, const char* tag):Collider(owner,tag,false)
{
}

CircleCollider::CircleCollider(std::shared_ptr<Character> owner, const char* tag,Circle c):Collider(owner, tag,false),circle_(c)
{
}

bool CircleCollider::IsHit(std::shared_ptr<Collider> col)
{
	assert(col != nullptr);
	auto ccol = std::dynamic_pointer_cast<CircleCollider>(col);
	if (ccol != nullptr) {
		auto& other = ccol->circle_;
		Circle a = {ActualPosition(),circle_ .radius};
		Circle b = {ccol->ActualPosition(),ccol->circle_.radius };
		auto sqDiff = (a.center - b.center).SQMagnitude();
		auto totalRadius = a.radius + b.radius;
		return sqDiff <= totalRadius* totalRadius;
	}
	return false;
}
const Position2f CircleCollider::ActualPosition()
{
	return circle_.center + GetOwner()->Pos();
}
void CircleCollider::Draw() {
	if (OwnerIsDead())return;
	auto& pos = ActualPosition();
	uint32_t col = 0xffffff;
	if (GetTag() == "patk") {
		col = 0xffaaaa;
	}

	DrawCircle(pos.x, pos.y, static_cast<int>(circle_.radius), col, false);
}

const Circle& CircleCollider::GetCircle() const
{
	return circle_;
}
