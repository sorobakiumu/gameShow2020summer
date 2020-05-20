#include "CheckHitManage.h"
#include "DxLib.h"


std::unique_ptr<CheckHitManage, CheckHitManage::CheckHitManageDeleter> CheckHitManage::sInstance(new CheckHitManage);

bool CheckHitManage::CheckHit(Vec2double pos1, Vec2double pos2)
{
	_pos1 = pos1;
	_pos2 = pos2;

	if ((_pos1.x - regu.x) < (_pos2.x - regu.x) + )
	{


	}
	return false;
}

CheckHitManage::CheckHitManage()
{
	regu = { 16 , 16 };
}

CheckHitManage::~CheckHitManage()
{

}
