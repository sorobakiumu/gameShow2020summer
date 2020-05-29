#include "shot.h"

// ｺﾝｽﾄﾗｸﾀ
shot::shot()
{

}

// 指定付きｺﾝｽﾄﾗｸﾀ
shot::shot(Vec2double pos, Vec2Int size , PLSTATE _state)
{
	MapPos = pos;			// 座標初期化

	startPos = pos;			// 

	size = size;			// ｻｲｽﾞ初期化

	moveState = _state;		// 進行方向設定

	ID = OBJ_ID::PLAYER;	// ｵﾌﾞｼﾞｪｸﾄ属性設定

	Init();					// その他初期化
}

shot::~shot()
{
}


// 攻撃制御関数
bool shot::shotMove(void)
{
	switch (moveState)
	{
	case PLSTATE::WORKL:
		MapPos.x = MapPos.x - 3.0;

		if (MapPos.x - startPos.x == -1800)
		{
			return false;
		}

		break;

	case PLSTATE::WORKR:
		MapPos.x = MapPos.x + 3.0;
		
		if (MapPos.x - startPos.x == 1800)
		{
			return false;

		}

		break;


		break;

	default:
		break;
	}

	
	return true;

}

// player初期化
void shot::Init(void)
{
	Rad = 0;

	 
	
}

void shot::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpImageMng.GetMap("弾") , LAYER::PLAYER, 999));
}

void shot::UpDate()
{
}
