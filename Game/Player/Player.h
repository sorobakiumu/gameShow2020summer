#pragma once
#include "../Character.h"
#include <memory>
#include <vector>
#include <array>
//プレイヤークラス
class PlayerInputListener;
class GamePlaingScene;
class InputLitener;
class Equipment;
class CollisionManager;
class Player :
	public Character
{
private:
	std::unique_ptr<InputLitener> inputListener_;
	std::vector<std::shared_ptr<Equipment>> em_;
	size_t crrentEquipmentNo_ = 0;
	std::shared_ptr<CollisionManager> collisionManager_;

	const int ground_line = 480;
	std::array<Position2f, 41> moveHistory_;
	size_t currentMoveIndex_ = 0;
	void NormalDraw();
	void JampDraw();
	void FallDraw();
	GamePlaingScene* gs_;
	int run_[6];
	int jamp[4];
	int wjamp[4];
	int fall[2];
	int knockbackFrame_ = 0;//ノックバックのフレーム
	int playerLife_ = 100;
public:
	void DoubleAttack(const Input& input);
	using DrawFunction_t = void (Player::*)();
	DrawFunction_t Drawer_;
	void DoubleJampDraw();
	void SetPosition(const Vector2f);
	Vector2f GetPosition();
	void Update()override;
	void Draw()override;
	void Move(const Vector2f, Input input);
	void Attack(const Input& input);
	int CrrentEquipmentNo_()const;
	void OnHit(CollisionInfo&, CollisionInfo&)override;
	void Jamp();
	void RiseUpdate();
	void FallUpdate();
	void NormalUpdate();
	void DamageUpdate();
	float accelY_;
	float velY_;
	bool left = false;
	using UpdateFunction_t = void (Player::*)();
	UpdateFunction_t updater_;
	int jampCnt = 0;
	Player(GamePlaingScene* gs, std::shared_ptr<Camera> camera);
	~Player();
};
