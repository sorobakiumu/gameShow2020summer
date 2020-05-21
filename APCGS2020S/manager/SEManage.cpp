#include "SEManage.h"
#include "DxLib.h"

std::unique_ptr<SEManage, SEManage::SEManageDeleter> SEManage::sInstance(new SEManage);


SEManage::SEManage()
{
	
	seNum = 0;

}

SEManage::~SEManage()
{

}

const void SEManage::readMusic(std::string& key , std::string& str)
{
	if (seMap.find(key) == seMap.end())
	{
		seNum = LoadSoundMem(str.c_str());

		seMap[key] = seNum;

	}

	// ���𗬂������ۂ͈ȉ��̺��ނ��g�p���邱��
	// ٰ�ߖ��A������Đ�
	// PlaySoundMem(seMap[key], DX_PLAYTYPE_BACK, true);

	// ٰ�ߗL�A������Đ�(BGM����)
	// PlaySoundMem(seMap[key], DX_PLAYTYPE_LOOP , true);
}

