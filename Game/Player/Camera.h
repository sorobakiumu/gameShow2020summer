#pragma once
#include"../../Geometry.h"
#include<memory>
class Player;
class Camera
{
private:
	std::shared_ptr<Player> player_;
	Position2f pos_;
	Rect stageSize;//デフォルトは800x600にする
	bool is_locked = false;
public:
	void lock() { is_locked = true; }
	void setPlayer(std::shared_ptr<Player>);
	const void SetSize(Size size);
	const Position2f& GetPosition();
	const Rect GetViewRange();
	const Vector2f ViewOffset()const;
	void Update();
	Camera();
};

