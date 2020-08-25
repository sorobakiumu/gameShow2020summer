#pragma once
#include "../Geometry.h"
#include <memory>
#include <list>
class Effect
{
protected:
	int frame = 0;
	Position2 pos_;
	bool isDeletable_ = false;
public:
	Effect(Position2 p);
	bool IsDead() { return isDeletable_;}
	void UpDate();
	void Draw();
};

class EffectMng
{
private:
	std::list<std::shared_ptr<Effect>> effectList_;
public:
	void EmitBlow(Position2f pos);
	void Update();
	void Draw();
};

class EmitBlat:
	public Effect
{
public:
	//void UpDate()override;
	//void Draw()override;
};

class EmitBlow :
	public Effect
{
public:
	//void Update()override;
	//void Draw()override;
};

