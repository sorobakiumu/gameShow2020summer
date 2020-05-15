#include "player.h"
#include "DxLib.h"

// playerのコンストラクタ
player::player()
{
	Init();
}

// playerの初期座標とsizeを設定
player::player(Vec2double _pos, Vec2Int _size)
{
	// playerの初期座標とsizeを設定
	Pos = _pos;

	// ｻｲｽﾞ代入
	Size = _size;

	// 対象識別付与
	ID = OBJ_ID::PLAYER;

	// 初期化
	Init();
}

player::~player()
{

}


void player::Update(void)
{

	switch (ptn)
	{
	case KeyBoard:

		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Pos.x = Pos.x - 5.0;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Pos.x = Pos.x + 5.0;
		}
				 
		if (CheckHitKey(KEY_INPUT_UP) == 1 && jmpFlg == 0)
		{
			jpCtlFlag = 1;
		}
		break;

	case Pad:

		break;

	default:

		break;

	}


	if (jpCtlFlag == 1)
	{
		Pos.y = pow((sec - 180), 2) * (60/180) + lpSceneMng.ScreenSize.y - Size.y;

		sec++;
	}


}

void player::Init(void)
{
	sec = 0;
	jmpFlg = 0;
	jmpCnt = 180;
	jpCtlFlag = 0;
}
