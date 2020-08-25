#include "Effect.h"

Effect::Effect(Position2 p) :pos_(p)
{
}

void Effect::UpDate()
{
}

void Effect::Draw()
{
}

void EffectMng::EmitBlow(Position2f pos)
{
}

void EffectMng::Update()
{
	for (auto& e : effectList_)
	{
		e->UpDate();
	}
}

void EffectMng::Draw()
{
	for (auto& e : effectList_)
	{
		e->Draw();
	}
}
