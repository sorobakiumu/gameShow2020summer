#include "shot.h"

// ｺﾝｽﾄﾗｸﾀ
shot::shot()
{
	Init();					// その他初期化
	moveState = PLSTATE::STOPR;

}

// 指定付きｺﾝｽﾄﾗｸﾀ
shot::shot(Vec2double pos, Vec2Int size , PLSTATE _state)
{
	Init();					// その他初期化

	MapPos = pos;			// 座標初期化

	startPos = pos;			// 

	size = size;			// ｻｲｽﾞ初期化

	moveState = _state;		// 進行方向設定

	ID = OBJ_ID::PLAYER;	// ｵﾌﾞｼﾞｪｸﾄ属性設定

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
	
		// 弾の移動確認(左)
		MapPos.x = MapPos.x - 3.0;

		// 
		if (MapPos.x - startPos.x == -1800)
		{
			return false;
		}

		break;

	case PLSTATE::WORKR:
	
		// 弾の移動確認(右)
		MapPos.x = MapPos.x + 3.0;
		
		// 
		if (MapPos.x - startPos.x == 1800)
		{
			return false;

		}

		break;

	default:
		break;
	}

	
	return true;

}

// shot初期化
void shot::Init()
{
	Rad = 0.0;

	moveState = PLSTATE::STOPR;
}

void shot::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, Rad, lpImageMng.GetMap("弾") , LAYER::PLAYER, 999));
}

void shot::UpDate()
{
	shotMove();

	Draw();
}
