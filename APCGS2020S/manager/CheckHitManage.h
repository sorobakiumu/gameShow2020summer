#pragma once
#include "../Obj/Obj.h"
#include "DxLib.h"
#include <memory>
#include "..\Common\Vector2.h"
#include <map>
#include <vector>
#include <string>

#define lpCHMng CheckHitManage::GetInstance();


class CheckHitManage
{
public:

	// sInstanceの中に入っている、CheckHItManageのﾎﾟｲﾝﾀ(ｱﾄﾞﾚｽ)を返す
	static CheckHitManage& GetInstance(void)
	{
		return *sInstance;
	}

private:

	// ChackHitMangeのDeleter
	struct CheckHitManageDeleter
	{
		void operator()(CheckHitManage* chMng) const
		{
			delete chMng;
		}
	};

	// 衝突識別関数(識別したいもの同士の座標を入れる)
	bool CheckHit( Vec2double pos1 , Vec2double pos2);


	CheckHitManage();
	~CheckHitManage();


	static std::unique_ptr<CheckHitManage, CheckHitManageDeleter> sInstance;


	// 座標代入変数
	Vec2double _pos1;
	Vec2double _pos2;
	
	// 矩形を取るための
	Vec2double regu;

};

