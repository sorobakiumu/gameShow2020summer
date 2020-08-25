#include "keyconfig.h"
#include <DxLib.h>
#include"../System/Input.h"

namespace {
	constexpr int menu_y_interval = 48;//ÉÅÉjÉÖÅ[ÇÃéöä‘
//	template<template T>
	inline int ModuloIncrement(const int& value, const int& modulo) {
		static_assert(std::is_integral<int>::value,"êÆêîå^Ç…å¿ÇÈ");
		return (value + 1) % modulo;
	}
	inline int ModuloDecrement(const int& value, const int& modulo) {
		static_assert(std::is_integral<int>::value, "êÆêîå^Ç…å¿ÇÈ");
		return (value + modulo - 1) % modulo;
	}
	inline bool Is(const int& val, const int& div) {
		static_assert(std::is_integral<int>::value, "êÆêîå^Ç…å¿ÇÈ");
		return val % div == 0;
	}
}


keyconfig::keyconfig(SceneController& c, Position2 pos):Scene(c),pos_(pos)
{
	updater_ = &keyconfig::InitializeUpdate;
}

void keyconfig::Update(const Input& input)
{
	(this->*updater_)(input);
}

void keyconfig::Draw()
{
	//SetDrawBlendMode(DX_BLENDMODE_MULA, 200);
	DrawBox(pos_.x, pos_.y, pos_.x + 400, pos_.y + 400, 0xaaffaa, true);
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(pos_.x, pos_.y, pos_.x + 400, pos_.y + 400, 0xffffff, false);
	DrawString(pos_.x + 150, pos_.y + 20, L"keyconfig", 0xff0000);
	int n = 0;
	int collar = 0x000000;
	int changeCollar = 0xffaaaa;
	int editCollar = 0x0000ff;
	int indent = 0;
	if (updater_ == &keyconfig::EditUpdate)
	{
		changeCollar = editCollar;
	}
	for (auto k : DrawkeyList) {
		if (crrentNum == n)
		{
			collar = changeCollar;
			indent += 5;
		}
		DrawFormatString(pos_.x + 20+indent, pos_.y + menu_y_interval * n+ menu_y_interval, collar, L"%s", k.c_str());
		collar = 0x000000;
		indent = 0;
		n++;
	}
	n = 0;
	int n2 = 0;
	for (auto p : peripheralReferenceTable_) {
		for (auto i : p.second)
		{
			if (i.type == PeripheralType::keyboard)
			{
				if (crrentNum == n)
				{
					collar = changeCollar;
					indent += 5;
				}
				DrawFormatString(pos_.x + 100 + indent, pos_.y + menu_y_interval * n+ menu_y_interval, collar, L"keyboard==%04x", i.inputidx);
				collar = 0x000000;
				indent = 0;
				n++;
			}
			else if (i.type == PeripheralType::gamepad)
			{
				if (crrentNum == n2)
				{
					collar = changeCollar;
					indent += 5;
				}
				DrawFormatString(pos_.x + 250 + indent, pos_.y + menu_y_interval * n2+menu_y_interval, collar, L"gamepad==%04x", i.inputidx);
				collar = 0x000000;
				indent = 0;
				n2++;
			}
		}
	}
}

void keyconfig::InitializeUpdate(const Input& input)
{
	if (peripheralReferenceTable_.empty()) {
		std::string removableEvents[] = { "up","down","left","right" };
		for (const auto& ref : input.peripheralReferenceTable_) {
			if (count(begin(removableEvents), end(removableEvents), ref.first) == 0) {
				peripheralReferenceTable_.insert(ref);
			}
		}
	}
	for (auto p : peripheralReferenceTable_) {
		DrawkeyList.emplace_back(input.GetWideStringFromString(p.first.c_str()));
	}
	for (auto p : peripheralReferenceTable_) {
		keyList.emplace_back(p.first.c_str());
	}
	keyList.emplace_back("åàíË");
	DrawkeyList.emplace_back(L"åàíË");
	updater_ = &keyconfig::NomalUpdate;
}

void keyconfig::NomalUpdate(const Input& input)
{
	if (input.IsTriggerd("up")) {
		if (crrentNum == 0)
		{
			crrentNum = keyList.size()-1;
		}
		else
		{
			crrentNum--;
		}
	}
	if (input.IsTriggerd("down")) {
		if (crrentNum == keyList.size()-1)
		{
			crrentNum = 0;
		}
		else
		{
			crrentNum++;
		}
	}
	if (input.IsTriggerd("OK")) {
		if (crrentNum != keyList.size()-1)
		{
			updater_ = &keyconfig::EditUpdate;
			input.UnlockRawMode();
		}
		else {
			CommitCurrentKeyConfig(input);
			controller_.PopScene();
		}
	}
}

void keyconfig::EditUpdate(const Input& input)
{
	if (input.IsTriggerd("OK")) {
		updater_ = &keyconfig::NomalUpdate;
		input.LockRawMode();
	}

	for (auto& p : peripheralReferenceTable_[keyList[crrentNum]]){
		if (p.type == PeripheralType::keyboard) {
			for (unsigned int i = 0; i < input.GetRawKeyState().size(); i++) {
				if ((bool)input.GetRawKeyState()[i] == true) {
					if (p.inputidx != i) {
						p.inputidx = i;
					}
				}
			}
		}
	}
}

void keyconfig::CommitCurrentKeyConfig(const Input& input)
{
	input.SetperipheralReferenceTable(peripheralReferenceTable_);
}

