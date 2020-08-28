#pragma once
#include "../Geometry.h"
#include <memory>
#include <list>
class Player;
class Camera;
class Effect
{
protected:
	int frame = 0;
	bool isDeletable_ = false;
	std::shared_ptr<Camera> camera_;
public:
	Effect(std::shared_ptr<Camera> camera);
	bool IsDead() { return isDeletable_; }
	virtual void UpDate() = 0;
	virtual void Draw() = 0;
};

class EffectMng
{
private:
	std::list<std::shared_ptr<Effect>> effectList_;
public:
	EffectMng();
	void EmitBlow(Position2f pos);
	void CollPlayerCharge(Player* player, std::shared_ptr<Camera> camera);
	void Update();
	void Draw();
};

class EmitBlat :
	public Effect
{
public:
	void UpDate()override;
	void Draw()override;
};

class EmitBlow :
	public Effect
{
public:
	void UpDate()override;
	void Draw()override;
};

class PlayerCharge :
	public Effect
{
public:
	PlayerCharge(Player* player, std::shared_ptr<Camera> camera);
	void UpDate()override;
	void Draw()override;
	int charge[4];
	int flame;
	Player* player_;
};
