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

	// sInstance�̒��ɓ����Ă���ACheckHItManage���߲��(���ڽ)��Ԃ�
	static CheckHitManage& GetInstance(void)
	{
		return *sInstance;
	}

private:

	// ChackHitMange��Deleter
	struct CheckHitManageDeleter
	{
		void operator()(CheckHitManage* chMng) const
		{
			delete chMng;
		}
	};

	// �Փˎ��ʊ֐�(���ʂ��������̓��m�̍��W������)
	bool CheckHit( Vec2double pos1 , Vec2double pos2);


	CheckHitManage();
	~CheckHitManage();


	static std::unique_ptr<CheckHitManage, CheckHitManageDeleter> sInstance;


	// ���W����ϐ�
	Vec2double _pos1;
	Vec2double _pos2;
	
	// ��`����邽�߂�
	Vec2double regu;

};

