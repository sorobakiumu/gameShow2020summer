#pragma once
#include <memory>
#include "..\Common\Vector2.h"
#include <map>
#include <vector>
#include <string>

using VecInt = std::vector<int>;

#define lpImageMng  ImageManage::GetInstance()

class ImageManage
{
public:
	static ImageManage &GetInstance(void)
	{
		return *sInstance;
	}

	// �摜�ǂݍ���(�v���O������)
	const VecInt& GetID(const std::string& key);

	// �摜�ǂݍ���(�P��)
	const VecInt& GetID(const std::string& key,
						const std::string& fileName);

	// �����摜�ǂݍ���
	const VecInt& GetID(const std::string& key,
		const std::string& fileName,
		const Vec2Int& divsize,
		const Vec2Int& divCnt);

	const int GetMap(const std::string& key);

private:
	struct ImageManageDeleter
	{
		void operator()(ImageManage* imageMng) const
		{
			delete imageMng;
		}
	};


	ImageManage();
	~ImageManage();

	static std::unique_ptr<ImageManage, ImageManageDeleter> sInstance;

	std::map <std::string, VecInt> imgMap;
	std::map <std::string, int> sImgMap;

};

