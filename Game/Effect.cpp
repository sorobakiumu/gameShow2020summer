#include "Effect.h"
#include "../System/FileManager.h"
#include "../System/File.h"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <DxLib.h>
#include "../Game/Player/Camera.h"
#include "Player/Player.h"

using namespace std;

Effect::Effect(std::shared_ptr<Camera> camera):camera_(camera)
{
}

EffectMng::EffectMng()
{
	effectList_.size();
}

void EffectMng::EmitBlow(Position2f pos)
{
}

void EffectMng::CollPlayerCharge(Player* player, std::shared_ptr<Camera> camera)
{
	effectList_.emplace_back(std::make_shared<PlayerCharge>(player,camera));
}

void EffectMng::Update()
{
	for (auto& e : effectList_)
	{
		e->UpDate();
	}
	auto it = std::remove_if(effectList_.begin(), effectList_.end(),
		[](std::shared_ptr<Effect>& e) {
			return e->IsDead();
		});
	effectList_.erase(it, effectList_.end());


}

void EffectMng::Draw()
{
	for (auto& e : effectList_)
	{
		e->Draw();
	}
}

void EmitBlow::UpDate()
{
}

void EmitBlow::Draw()
{
}

void EmitBlat::UpDate()
{
}

void EmitBlat::Draw()
{
}

PlayerCharge::PlayerCharge(Player* player, std::shared_ptr<Camera> camera) :Effect(camera),player_(player)
{
	for (int i = 0; i < _countof(charge); ++i) {
		wstringstream wss;
		wss << L"image/Effect/charge/NPT10";
		wss << i;
		wss << ".png";
		charge[i] = FileManager::Instance().Load(wss.str().c_str(), "PL")->Handle();
	}
	frame = 0;
}

void PlayerCharge::UpDate()
{
	frame++;

	isDeletable_ = (player_->IsTimeStop());
}

void PlayerCharge::Draw()
{
	auto offset = camera_->ViewOffset().x;
	DrawRotaGraph(player_->GetPosition().x + offset, player_->GetPosition().y-50, 0.2f, 0.0f, charge[(frame/4) % 4], true);
}