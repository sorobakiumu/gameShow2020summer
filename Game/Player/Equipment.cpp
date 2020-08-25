#include "Equipment.h"
#include "Camera.h"

Equipment::Equipment(std::shared_ptr<CollisionManager> c, std::shared_ptr<Camera> camera):collisionManager_(c),camera_(camera)
{
}

Equipment::Equipment()
{
}