#pragma once
#include <string>
#include <vector>
#include<unordered_map>
#include"../Scene/keyconfig.h"

enum class PeripheralType
{
	keyboard,
	gamepad
};


struct PeripheralInfo {
	PeripheralType  type;
	int inputidx;
};
class Input
{
	friend keyconfig;
public:
	Input();
	void Update();
	//押してるかどうかを返す
	//コマンド文字列
	//押されている
	bool IsPressed(const char* cmd) const;
	//押された瞬間なのか返す
	//押されてない:false
	//今押されて直前も押されている:false
	//今押されて直前は押されていない:true
	bool IsTriggerd(const char* cmd) const;
	//話された瞬間なのか返す
	//押されてる:false
	//今押されていて直前は押されていない:false
	//今押されてなく直前は押されている:true
	bool IsReleased(const char* cmd) const;

	//現在の入力情報を参照で返す
	bool& CurrentInput(const char* cmd)const;
	bool GetCurretInput(const std::string cmd)const;

	//直前の入力情報を参照を返す
	bool& LastInput(const std::string cmd)const;

	/// <summary>
	/// イベントに対応する機器入力を登録する
	/// </summary>/// <param name="eventname">入力イベント名</param>
	/// <param name="peri">機器入力情報配列(ベクタ)</param>
	void RegistAcceptPeripheral(const char* eventname, const std::vector<PeripheralInfo>& peri);
	mutable std::unordered_map <std::string, std::vector<PeripheralInfo >> peripheralReferenceTable_;

	bool CheckPressed(const char*, char* key, int pad);

	void RecordInput(const char*, char*, int);

	std::wstring GetWideStringFromString(const std::string& str)const;
	int gamePad;
private:
	mutable std::vector<char> rawkeystate_;
	mutable int rawpadstate_;
	mutable bool isRawMode_ = false;

	void UnlockRawMode()const;
	void LockRawMode()const;

	void SetperipheralReferenceTable(const std::unordered_map <std::string, std::vector<PeripheralInfo >> ref)const;

	const std::vector<char> GetRawKeyState()const;
};
//入力通知を受け取る(インターフェース)
class InputLitener
{
public:
	//毎フレーム呼ばれる
	//入力を受け取る
	virtual void Notify(const Input& input) = 0;

};
