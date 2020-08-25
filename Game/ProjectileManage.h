#pragma once
#include "Projectile.h"
#include <list>
#include<memory>
class CollisionManager;
class Camera;
class ProjectileManage :
	public Projectile
{
private:
	std::list<std::shared_ptr<Projectile>> project_;
public:
	ProjectileManage(std::shared_ptr<Camera> camera);
	std::list<std::shared_ptr<Projectile>> GetProjecties();
	void AddProjectile(Projectile*);
	ProjectileManage& projectilemanage() { return *this; }
	void Update();
	void Draw();
	void OnHit(CollisionInfo&, CollisionInfo&)override;

};

