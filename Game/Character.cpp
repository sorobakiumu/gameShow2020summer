#include "Character.h"
#include "../Geometry.h"
#include "player/Camera.h"

using namespace std;

Character::Character(std::shared_ptr<Camera> camera):camera_(camera)
{
}

Position2f Character::Pos()
{
	auto pos = pos_;
	pos.x += camera_->ViewOffset().x;
	return pos; 
}
