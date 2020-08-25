#pragma once
#include "FileManager.h"
///<summary>
///�t�@�C�����̂��̂�\��
///</summary>
class File :
	public FileManager
{
	friend FileManager;
public:
	///<summary>
///�t�@�C���̎��
///</summary>
	enum class Type {
		image,//�摜�t�@�C��
		sound,//�T�E���h�t�@�C��(BGM ������)
		data//����ȊO�̃f�[�^�n
	};
	~File();
	int Handle()const;
	std::vector<uint8_t> Data();
	bool IsLoaded()const;
	const std::string GetTag();
	template<typename T>
	void CopyRead(T* data, size_t num) { 
		FCopyRead(data, sizeof(T) * num); 
	}
	template<typename T>
	void CopyRead(T& data) { 
		FCopyRead(&data, sizeof(T)); 
	}
private:
	void FCopyRead(void* data, size_t size);
	size_t cursor_ = 0;
	std::string tag_;//�^�O
	int handle_;//�t�@�C���n���h��(�摜�A�T�E���h�̎��Ɏg�p)
	std::vector<uint8_t> data_;//�f�[�^�^�̎��݂̂Ɏg�p
	Type type_;
	File(int h, Type type, const char* tag = "");

};

