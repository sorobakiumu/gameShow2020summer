#pragma once
#include "FileManager.h"
///<summary>
///ファイルそのものを表す
///</summary>
class File :
	public FileManager
{
	friend FileManager;
public:
	///<summary>
///ファイルの種別
///</summary>
	enum class Type {
		image,//画像ファイル
		sound,//サウンドファイル(BGM を除く)
		data//それ以外のデータ系
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
	std::string tag_;//タグ
	int handle_;//ファイルハンドル(画像、サウンドの時に使用)
	std::vector<uint8_t> data_;//データ型の時のみに使用
	Type type_;
	File(int h, Type type, const char* tag = "");

};

