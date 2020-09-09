#include "GamePlaingScene.h"
#include"CountinueScene.h"
#include "DxLib.h"
#include "../System/Input.h"
#include"PauseScene.h"
#include "../Game/Player/Player.h"
#include "../Game/Background.h"
#include <deque>
#include "../Game/ProjectileManage.h"
#include"../Game/Enemy/EnemyManager.h"
#include"../Game/Enemy/Spawner.h"
#include"../Game/Enemy/SideSpawner.h"
#include"../Game/Enemy/Slaher.h"
#include"../Game/Collision/CollisionManager.h"
#include "../Game/Collision/CircleCollider.h"
#include"../Game/Stage.h"
#include"../Game/Player/Camera.h"
#include"../Game/Effect.h"
#include"../System/File.h"
#include"../System/FileManager.h"

using namespace std;

namespace {
	const int fadeouto_interval = 45;
	int waitTimer_;

	int equipNo_[2];

	int frmCnt;

	int screenH = -1;
	int shader = -1;
}
GamePlaingScene::GamePlaingScene(SceneController& c) :Scene(c), updater_(&GamePlaingScene::InitializeUpdate),drawer_(&GamePlaingScene::FadeInDraw)
{
	C = Circle(Vector2f(400,300),600);
	if (shader == -1)
	{
		shader = LoadPixelShader(L"image/Etc/testps.pso");
	}
	if (screenH == -1)
	{
		screenH = MakeScreen(800, 600);
	}
}

void GamePlaingScene::NomalUpdate(const Input& input)
{
	
	if (waitTimer_ >0) {
		return;
	}
	if (input.IsTriggerd("OK")) {
		updater_ = &GamePlaingScene::FastBlinkUpdate;
		waitTimer_ = 30;
	}
	if (input.IsTriggerd("pause")) {
		controller_.pushScene(new PauseScene(controller_));
	}		
	collisonManager_->Update();
	player_->Update();
	bg_->Update();
	if (!player_->IsTimeStop()) {
		projectileManager_->Update();
		enemyManager_->UpDate();
	}

	stage_->Update();
	effectManager_->Update();
	if (stage_->IsBossMode())
	{
		camera->lock();
	}
	camera->Update();
	if (!player_->IsTimeStop()) {
		for (auto& spw : spawners)
		{
			spw->Update();
		}
	}
	for (auto& lisner : listeners)
	{
		lisner->Notify(input);
	}

	if (!player_->IsTimeStop())
	{
		C.SetRad(0);
	}
	else if (player_->IsTimeStop())
	{
		C.AddRad(20);
		C.SetCenter(player_->GetCameraPos());
	}
}

void GamePlaingScene::FastBlinkUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		updater_ = &GamePlaingScene::FadeoutUpdate;
		waitTimer_ = fadeouto_interval;
		drawer_ = &GamePlaingScene::FadeOutDraw;
	}
}

void GamePlaingScene::FadeoutUpdate(const Input&)
{
	if (--waitTimer_ == 0) {
		controller_.ChengeScene(new CountinueScene(controller_));
	}
}

void GamePlaingScene::InitializeUpdate(const Input&)
{
	
	waitTimer_ = 45;
	frmCnt = 0;

	equipNo_[0] = LoadGraph(L"image/UI/bomb.png");
	equipNo_[1] = LoadGraph(L"image/UI/sword.png");

	collisonManager_ = std::make_shared<CollisionManager>();


	auto gm = this;

	camera = std::make_shared<Camera>();
	effectManager_ = std::make_shared<EffectMng>();
	stage_ = std::make_shared<Stage>(camera,gm);


	projectileManager_ = make_unique<ProjectileManage>(camera);
	player_ = std::make_shared<Player>(gm, camera);
	player_->SetPosition(Vector2f(400, 500));
	camera->setPlayer(player_);

	bg_ = std::make_unique<Background>(camera);
	enemyManager_ = std::make_shared<EnemyManager>();
	//spawners.emplace_back(new SideSpawner(Position2f(0, 0), new Slasher(player_, camera, stage_), enemyManager_, collisonManager_, camera));


	camera->Update();
	stage_->Load(L"image/BG/level/level1.fmf", camera);

	collisonManager_->AddColliders(new CircleCollider(player_, "play", Circle(Vector2f(0, 0), 32)));

	updater_ = &GamePlaingScene::NomalUpdate;

}

void GamePlaingScene::NormalDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	bg_->Draw(player_->IsTimeStop());
	if (player_->IsTimeStop()) {
		//SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);

	}
	stage_->Draw();
	enemyManager_->Draw();
	projectileManager_->Draw();
	if (player_->IsTimeStop()) {
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		GetDrawScreenGraph(0, 0, 800, 600, screenH);
		C.ShaderDraw(shader, screenH);
	}
	player_->Draw();
	effectManager_->Draw();
	DrawRotaGraph(37, 37, 1.0f, 0.0, equipNo_[player_->GetCrrentEquipmentNo_()], true);
	DrawBox(7, 7, 64 + 7, 64 + 7, 0x000000, false);
	DrawBox(5, 5, 64 + 5, 64 + 5, 0xffffff, false);
	if (player_->IsTimeStop()) {
		//SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
	}
	collisonManager_->DebagDraw();
}

void GamePlaingScene::FadeOutDraw()
{
	NormalDraw();
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - waitTimer_) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void GamePlaingScene::FadeInDraw()
{
	NormalDraw();
	if (--waitTimer_ == 0) {
		drawer_ = &GamePlaingScene::NormalDraw;
	}
	auto blendparam = 255 * (static_cast<float>(fadeouto_interval - (fadeouto_interval - waitTimer_)) / static_cast<float>(fadeouto_interval));
	SetDrawBlendMode(DX_BLENDMODE_MULA, static_cast<int>(blendparam));
	DrawBox(0, 0, 800, 600, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

GamePlaingScene::~GamePlaingScene()
{

	FileManager::Instance().DeleteAllResources();
}

void GamePlaingScene::AddListener(InputLitener* listener)
{
	listeners.push_back(listener);
}

void GamePlaingScene::Update(const Input& input)
{
	frmCnt++;
	(this->*updater_)(input);
}

void GamePlaingScene::Draw()
{
	(this->*drawer_)();
}

ProjectileManage& GamePlaingScene::GetProjectileManage()
{
	return projectileManager_->projectilemanage();
}

std::shared_ptr<CollisionManager>& GamePlaingScene::GetCollisionManager()
{
	return collisonManager_;
}

std::shared_ptr<Player>& GamePlaingScene::GetPlayer()
{
	return player_;
}

std::shared_ptr<Stage>& GamePlaingScene::GetStage()
{
	return stage_;
}

std::shared_ptr<Camera>& GamePlaingScene::GetCamera()
{
	return camera;
}

std::shared_ptr<EnemyManager>& GamePlaingScene::GetEnemyManager()
{
	return enemyManager_;
}

std::shared_ptr<EffectMng>& GamePlaingScene::GetEffectMng()
{
	return effectManager_;
}

void GamePlaingScene::AddSpawner(Spawner* spawner)
{
	spawners.emplace_back(spawner);
}
