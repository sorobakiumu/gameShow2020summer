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
	//�����Ă邩�ǂ�����Ԃ�
	//�R�}���h������
	//������Ă���
	bool IsPressed(const char* cmd) const;
	//�����ꂽ�u�ԂȂ̂��Ԃ�
	//������ĂȂ�:false
	//��������Ē��O��������Ă���:false
	//��������Ē��O�͉�����Ă��Ȃ�:true
	bool IsTriggerd(const char* cmd) const;
	//�b���ꂽ�u�ԂȂ̂��Ԃ�
	//������Ă�:false
	//��������Ă��Ē��O�͉�����Ă��Ȃ�:false
	//��������ĂȂ����O�͉�����Ă���:true
	bool IsReleased(const char* cmd) const;

	//���݂̓��͏����Q�ƂŕԂ�
	bool& CurrentInput(const char* cmd)const;
	bool GetCurretInput(const std::string cmd)const;

	//���O�̓��͏����Q�Ƃ�Ԃ�
	bool& LastInput(const std::string cmd)const;

	/// <summary>
	/// �C�x���g�ɑΉ�����@����͂�o�^����
	/// </summary>/// <param name="eventname">���̓C�x���g��</param>
	/// <param name="peri">�@����͏��z��(�x�N�^)</param>
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
//���͒ʒm���󂯎��(�C���^�[�t�F�[�X)
class InputLitener
{
public:
	//���t���[���Ă΂��
	//���͂��󂯎��
	virtual void Notify(const Input& input) = 0;

};
