#pragma once
#include "DxLib.h"
#include <memory>
#include "..\Common\Vector2.h"
#include <map>
#include <vector>
#include <string>

#define lpSEMng  SEManage::GetInstance;

class SEManage
{
	// sInstance‚Ì’†‚É“ü‚Á‚Ä‚¢‚éASEM‚ÌÎß²İÀ(±ÄŞÚ½)‚ğ•Ô‚·
	static SEManage& GetInstance(void)
	{
		return *sInstance;
	}



	const void SEManage::readMusic(std::string& key, std::string& str);

private:

	struct SEManageDeleter
	{
		void operator()(SEManage* seMng) const
		{
			delete seMng;
		}
	};

	SEManage();
	~SEManage();

	static std::unique_ptr<SEManage, SEManageDeleter> sInstance;

	std::map <std::string, int> seMap;

	int seNum;
};

