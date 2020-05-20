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

	// 音を流したい際は以下のｺｰﾄﾞを使用すること
	// ﾙｰﾌﾟ無、頭から再生
	// PlaySoundMem(seMap[key], DX_PLAYTYPE_BACK, true);

	// ﾙｰﾌﾟ有、頭から再生(BGM推奨)
	// PlaySoundMem(seMap[key], DX_PLAYTYPE_LOOP , true);
}

