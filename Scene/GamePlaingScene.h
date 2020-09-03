#pragma once
#include "Scene.h"
#include "../Geometry.h"
#include <memory>
#include<vector>

class TitleScene;
class Player;
class Background;
class InputLitener;
class ProjectileManage;
class EnemyManager;
class Spawner;
class CollisionManager;
class Stage;
class Camera;
class EffectMng;
class GamePlaingScene :
	public Scene
{
	friend TitleScene;
private:
	GamePlaingScene(SceneController&);

	std::shared_ptr<Camera> camera;
	std::shared_ptr<EffectMng> effectManager_;
	std::shared_ptr<Stage> stage_;
	std::shared_ptr<Player> player_;
	std::unique_ptr<Background> bg_;
	std::unique_ptr<ProjectileManage> projectileManager_;
	std::shared_ptr<EnemyManager> enemyManager_;
	std::shared_ptr<CollisionManager> collisonManager_;
	std::vector<std::shared_ptr<Spawner>> spawners;

	void NomalUpdate(const Input&);
	void FastBlinkUpdate(const Input&);
	void FadeoutUpdate(const Input&);
	void InitializeUpdate(const Input&);

	using UpdateFunction_t = void (GamePlaingScene::*)(const Input&);
	UpdateFunction_t updater_;

	void NormalDraw();
	void FadeOutDraw();
	void FadeInDraw();
	void (GamePlaingScene::* drawer_)();

	std::vector<InputLitener*> listeners;
	Circle C;
public:
	~GamePlaingScene();
	void AddListener(InputLitener* listener_);
	void Update(const Input&)override;
	void Draw()override;
	ProjectileManage& GetProjectileManage();
	std::shared_ptr<CollisionManager>& GetCollisionManager();
	std::shared_ptr<Player>& GetPlayer();
	std::shared_ptr<Stage>& GetStage();
	std::shared_ptr<Camera>& GetCamera();
	std::shared_ptr<EnemyManager>& GetEnemyManager();
	std::shared_ptr<EffectMng>& GetEffectMng();
	void AddSpawner(Spawner* spawner);
};