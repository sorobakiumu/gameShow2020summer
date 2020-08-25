#pragma once
#include "Scene.h"
#include "../Geometry.h"
#include<unordered_map>
#include<string>
struct PeripheralInfo;

class keyconfig :
	public Scene
{
	friend Input;
public:
	keyconfig(SceneController&,Position2);
	void Update(const Input&)override;
	void Draw()override;
private:
	//�������̂��߂̃A�b�v�f�[�g
	//���̃L�[�̊��蓖�ĂȂǂ�ǂݍ���
	void InitializeUpdate(const Input& input);

	//�ʏ펞�̃A�b�v�f�[�g
	void NomalUpdate(const Input& input);

	//�ҏW���̃A�b�v�f�[�g
	void EditUpdate(const Input& input);

	void CommitCurrentKeyConfig(const Input& input);

	using UpdateFunction_t = void (keyconfig::*)(const Input&);
	UpdateFunction_t updater_;

	std::unordered_map <std::string, std::vector<PeripheralInfo >> peripheralReferenceTable_;
	Position2 pos_;
	std::vector<std::string>   keyList;
	std::vector<std::wstring>   DrawkeyList;
	int crrentNum=0;

};

