#include "ImageManage.h"
#include "..\Common\Vector2.h"
#include <map>
#include <vector>
#include "DxLib.h"

std::unique_ptr<ImageManage, ImageManage::ImageManageDeleter> ImageManage::sInstance(new ImageManage);

// ‰æ‘œ“Ç‚İ‚İ
const VecInt& ImageManage::GetID(const std::string& key)
{
	return GetID(key, key);
}

// ‰æ‘œ“Ç‚İ‚İ(’P‰æ)
const VecInt& ImageManage::GetID(const std::string& key, const std::string& fileName)
{
	if (imgMap.find(key) == imgMap.end())
	{
		if (imgMap.find(key) == imgMap.end())
		{
			imgMap[key].resize(1);
			imgMap[key][0] = LoadGraph(fileName.c_str());
		}
	}

	return imgMap[key];

}

// •ªŠ„‰æ‘œ“Ç‚İ‚İ
const VecInt& ImageManage::GetID(const std::string & key, const std::string & fileName, const Vec2Int& divSize, const Vec2Int & divCnt)
{

	if (imgMap.find(key) == imgMap.end())
	{
		imgMap[key].resize(divCnt.x * divCnt.y);

		LoadDivGraph(fileName.c_str(), (divCnt.x*divCnt.y), divCnt.x , divCnt.y, divSize.x, divSize.y, &imgMap[key][0]);
	}

	return imgMap[key];

}

const int ImageManage::GetMap(const std::string& key)
{
	return imgMap[key][0];
}

// ImageManage‚Ìºİ½Ä×¸À
ImageManage::ImageManage()
{

}

// ImageManage‚ÌÃŞ½Ä×¸À
ImageManage::~ImageManage()
{
}


