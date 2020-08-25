#include "ProjectileManage.h"
#include <algorithm>
#include "Player/Camera.h"

ProjectileManage::ProjectileManage(std::shared_ptr<Camera> camera):Projectile(camera)
{
}

std::list<std::shared_ptr<Projectile>> ProjectileManage::GetProjecties()
{
	return project_;
}

void ProjectileManage::AddProjectile(Projectile* p)
{
	project_.emplace_back(p);
}



void ProjectileManage::Update()
{
	for (auto& p : project_)
	{
		p->Update();
	}
	auto it = std::remove_if(project_.begin(), project_.end(),
		[](std::shared_ptr<Projectile>& p) {
			return p->IsDead();
		});
	project_.erase(it, project_.end());
}

void ProjectileManage::Draw()
{
	for (auto& p : project_)
	{
		p->Draw();
	}
}

void ProjectileManage::OnHit(CollisionInfo&, CollisionInfo&)
{
}
