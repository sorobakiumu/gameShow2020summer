#pragma once
#include "../Obj/Obj.h"
#include "DxLib.h"
#include <memory>
#include "..\Common\Vector2.h"
#include <map>
#include <vector>
#include <string>

#define lpSEMng  SEManage::GetInstance;


class CheckHitManage
{
public:

	// sInstance‚Ì’†‚É“ü‚Á‚Ä‚¢‚éASEM‚ÌÎß²İÀ(±ÄŞÚ½)‚ğ•Ô‚·
	static CheckHitManage& GetInstance(void)
	{
		return *sInstance;
	}

private:

	struct CheckHitManageDeleter
	{
		void operator()(CheckHitManage* chMng) const
		{
			delete chMng;
		}
	};


	bool CheckHit( Vec2double pos1 , Vec2double pos2);


	CheckHitManage();
	~CheckHitManage();


	static std::unique_ptr<CheckHitManage, CheckHitManageDeleter> sInstance;

	Vec2double _pos1;
	Vec2double _pos2;

	Vec2double regu;

};

