#include "Camera.h"
#include "Player.h"
#include <algorithm>
#include "../../System/Application.h"
#include <math.h>

template<typename T>
T Clamp(T value, T minvalue, T maxvalue) {
	return std::min(std::max(value, minvalue), maxvalue);
}


void Camera::setPlayer(std::shared_ptr<Player> player)
{
	player_ = player;
}

const void Camera::SetSize(Size size)
{
}

const Position2f& Camera::GetPosition()
{
	return pos_;
}

const Rect Camera::GetViewRange()
{
	auto& app = Application::Instance();
	auto& viewport = app.GetViewport();
	auto cameraSize = viewport.GetSize();
	Rect r;
	r.pos.x = pos_.x - cameraSize.w / 2.0;
	r.pos.y = pos_.y - cameraSize.h / 2.0;
	r.size.h = stageSize.size.h;
	r.size.w = stageSize.size.w/8;
	return r;
}

const Vector2f Camera::ViewOffset() const
{
	auto& app = Application::Instance();
	auto& viewport = app.GetViewport();
	auto& cameraSize = viewport.GetSize();
	return Vector2f(cameraSize.w / 2.0f -pos_.x, cameraSize.h / 2.0f -pos_.y);
}

void Camera::Update()
{
	if (is_locked)return;
	auto& app = Application::Instance();
	auto& viewport = app.GetViewport();
	const auto cameraSize = viewport.GetSize();
	auto a = player_->GetPosition();
	pos_.x = Clamp(a.x, cameraSize.w / 2.0f, stageSize.size.w - cameraSize.w / 2.0f);
}

Camera::Camera()
{
	stageSize.size.h = 600;
	stageSize.size.w = 800*8;
}
