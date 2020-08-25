#include "Input.h"
#include"Application.h"
#include <DxLib.h>
#include <unordered_map>
#include <array>
#include <cassert>
#include <algorithm>


using namespace std;

namespace {
	constexpr int input_record_size = 2;///<summary>入力バッファ格納数</summary>
	int currentInputIndex_ = 0;///<summary>現在の入力バッファを指すインデックス</summary>
	using InputStateTable_t = unordered_map<string, bool>;
	array<InputStateTable_t, input_record_size> inputStateTable_;

	//次の入力バッファインデックスを返す
	int GetNextInputBufferIndex() {
		return 	currentInputIndex_ = (currentInputIndex_ + 1) % inputStateTable_.size();
	}



	//ひとつ前の入力バッファインデックスを返す
	int GetLastInputBufferIndex() {
		return (currentInputIndex_ + 1 + static_cast<int>(inputStateTable_.size())) % inputStateTable_.size();
	}



}


Input::Input()
{
	RegistAcceptPeripheral("OK", { {PeripheralType::keyboard,KEY_INPUT_RETURN}, {PeripheralType::gamepad,PAD_INPUT_R} });
	RegistAcceptPeripheral("pause", { {PeripheralType::keyboard,KEY_INPUT_P}, {PeripheralType::gamepad,PAD_INPUT_L} });
	RegistAcceptPeripheral("cancel", { {PeripheralType::keyboard,KEY_INPUT_ESCAPE}, {PeripheralType::gamepad,PAD_INPUT_Z} });
	RegistAcceptPeripheral("up", { {PeripheralType::keyboard,KEY_INPUT_UP}, {PeripheralType::gamepad,PAD_INPUT_UP} });
	RegistAcceptPeripheral("down", { {PeripheralType::keyboard,KEY_INPUT_DOWN}, {PeripheralType::gamepad,PAD_INPUT_DOWN} });
	RegistAcceptPeripheral("left", { {PeripheralType::keyboard,KEY_INPUT_LEFT}, {PeripheralType::gamepad,PAD_INPUT_LEFT} });
	RegistAcceptPeripheral("right", { {PeripheralType::keyboard,KEY_INPUT_RIGHT}, {PeripheralType::gamepad,PAD_INPUT_RIGHT} });
	RegistAcceptPeripheral("shot", { {PeripheralType::keyboard,KEY_INPUT_Z}, {PeripheralType::gamepad,PAD_INPUT_C} });
	RegistAcceptPeripheral("jump", { {PeripheralType::keyboard,KEY_INPUT_X}, {PeripheralType::gamepad,PAD_INPUT_A} });
	RegistAcceptPeripheral("chenge", { {PeripheralType::keyboard,KEY_INPUT_C}, {PeripheralType::gamepad,PAD_INPUT_X} });
}





void Input::Update()
{
	currentInputIndex_ = GetNextInputBufferIndex();
	
  	constexpr int keyboard_buffer_size = 256;
	char keyState[keyboard_buffer_size];
	GetHitKeyStateAll(keyState);
	auto& currentTbl = inputStateTable_[currentInputIndex_];
	int pad1 = 0;
	if (GetJoypadNum() > 0) {
		pad1 = GetJoypadInputState(DX_INPUT_PAD1);
	}


	for (auto a : peripheralReferenceTable_)
		{
			RecordInput(a.first.c_str(),keyState,pad1);
		}
	if (isRawMode_) {
		rawpadstate_ = pad1;
		std::copy(std::begin(keyState), std::end(keyState), rawkeystate_.begin());
	}
}

bool Input::IsPressed(const char* cmd) const
{

	return GetCurretInput(cmd);
}




bool Input::IsTriggerd(const char* cmd) const
{
	return (IsPressed(cmd)&&!(LastInput(cmd)));
}

bool Input::IsReleased(const char* cmd) const
{
	return (!IsPressed(cmd) && (LastInput(cmd)));;
}

bool& Input::CurrentInput(const char* cmd) const
{
	auto& currentTbl = inputStateTable_[currentInputIndex_];
	auto it = currentTbl.find(cmd);
	assert(it != currentTbl.end());
	return it->second;
}

bool Input::GetCurretInput(const std::string cmd) const
{
	auto& currentTbl = inputStateTable_[currentInputIndex_];
	auto it = currentTbl.find(cmd);
	assert(it != currentTbl.end());
	return it->second;
}

bool& Input::LastInput(const std::string cmd)const
{
	auto& currentTbl = inputStateTable_[GetLastInputBufferIndex()];
	auto it = currentTbl.find(cmd);
	assert(it != currentTbl.end());
	return it->second;
}

void Input::RegistAcceptPeripheral(const char* eventname, const vector<PeripheralInfo>& peri)
{
	peripheralReferenceTable_[eventname] = peri;
	for (auto i : inputStateTable_) {
	}
	inputStateTable_[0][eventname] = false;
	inputStateTable_[1][eventname] = false;
}

bool Input::CheckPressed(const char* name, char* key,int pad)
{
	bool ret = false;
	for (auto p : peripheralReferenceTable_[name])
	{
		if (p.type == PeripheralType::gamepad)
		{
			ret = ret||(pad & p.inputidx);
		}
		else if (p.type == PeripheralType::keyboard)
		{
			ret = CheckHitKey(p.inputidx);
		}
	}
	return ret;
}

void Input::RecordInput(const char* name, char* key, int pad)
{
	CurrentInput(name) = CheckPressed(name, key, pad);
}

std::wstring Input::GetWideStringFromString(const std::string& str) const
{
	auto num1 = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED | MB_ERR_INVALID_CHARS, str.c_str(), -1, nullptr, 0);
	std::wstring wstr;
	wstr.resize(num1);
	auto num2 = MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED| MB_ERR_INVALID_CHARS,str.c_str(), -1, &wstr[0], num1);
	assert(num1 == num2);//一応チェック
	return wstr	;
}

void Input::UnlockRawMode() const
{
	//この関数はconstだがmutable変数のみは編集可能としている。（keyConfigのみ）
	isRawMode_ = true;
	rawkeystate_.resize(256);
}

void Input::LockRawMode() const
{
	//この関数はconstだがmutable変数のみは編集可能としている。（keyConfigのみ）
	isRawMode_ = false;
	rawpadstate_ = 0;
	rawkeystate_.clear();
}

void Input::SetperipheralReferenceTable(const std::unordered_map<std::string, std::vector<PeripheralInfo>> ref)const
{
	for (auto& r : ref) {
		peripheralReferenceTable_[r.first] = r.second;
	}
}

const std::vector<char> Input::GetRawKeyState()const
{
	return rawkeystate_;
}
