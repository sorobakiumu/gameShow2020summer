#pragma once
#include "../Character.h"
#include <memory>
#include <vector>
#include <array>
#include <tuple>

enum class DIR
{
	LEFT,
	RIGHT,
	MAX
};

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

	float accelY_;
	float velY_;

	using UpdateFunction_t = void (Player::*)();
	UpdateFunction_t updater_;
	int jampCnt = 0;

	const int ground_line = 480;
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
	int cnt=0;
	bool timeStop=false;
	bool timeinterval = false;
	//std::vector<std::pair<Position2f, int>> movehistry_;
	std::array<std::tuple<Position2f, int ,bool>, 10> movehistory_;
	size_t currentMoveIndex_ = 0;
	void AddMovehistry(int gf);
	Position2f lastPos;
	int shadowMask;
	DIR dir;

	void RiseUpdate();
	void FallUpdate();
	void NormalUpdate();
	void DamageUpdate();
	void InitializeUpdate();

	void Death();


	void EquipNext();

	void TimeStopMove();

	void DoubleAttack(const Input& input);
	using DrawFunction_t = void (Player::*)();
	DrawFunction_t Drawer_;
	void DoubleJampDraw();


	void ShadowDraw(std::tuple<Position2f, int, bool> a);
	void Move(const Vector2f, Input input);
	void Attack(const Input& input);

	void OnHit(CollisionInfo&, CollisionInfo&)override;
	void Jamp();

	int sound;
	int lowSound;
	int soundCount=0;

	int espStart;
	int espEnd;

public:
	void Update()override;
	void Draw()override;

	void SetPosition(const Vector2f);
	Vector2f GetPosition();
	int GetCrrentEquipmentNo_()const;
	GamePlaingScene* GetGameScene();
	bool IsTimeStop();

	DIR GetDir();

	Player(GamePlaingScene* gs, std::shared_ptr<Camera> camera);
	~Player();
};
