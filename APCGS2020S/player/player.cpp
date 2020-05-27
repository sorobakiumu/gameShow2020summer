#include "player.h"
#include "DxLib.h"

// playerのｺﾝｽﾄﾗｸﾀ
player::player()
{
	Init();
}

// playerの初期座標とsizeを設定
player::player(Vec2double _pos, Vec2Int _size)
{
	// playerの初期座標とsizeを設定
	MapPos = _pos;

	// ｻｲｽﾞ代入
	Size = _size;


	// 対象識別付与
	ID = OBJ_ID::PLAYER;

	// 初期化
	Init();
}

// playerのﾃﾞｽﾄﾗｸﾀ
player::~player()
{

}

// ﾌﾟﾚｲﾔｰ情報の更新
void player::UpDate()
{
	// 操作方法によって変えます
	switch (ptn)
	{
	// ｷｰﾎﾞｰﾄﾞ使用時
	case KeyBoard:

		// 十字ｷｰ(左)入力時、左移動
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			MapPos.x = MapPos.x - 5.0;
		}
		// 十字ｷｰ(右)入力時、右移動
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			MapPos.x = MapPos.x + 5.0;
		}
        
		// 十字ｷｰ(上)入力時、跳躍
		if (CheckHitKey(KEY_INPUT_UP) == 1 && AnyFlag == false)
		{
			AnyFlag = true;
			jmpPos = MapPos;
		}
		break;

	// ｹﾞｰﾑﾊﾟｯﾄﾞ?使用時
	case Pad:

		// ﾊﾟｯﾄﾞ(左)入力時、左移動
		if (GetJoypadInputState(PAD_INPUT_LEFT) == 1)
		{
			MapPos.x = MapPos.x - 5.0;
		}
		// ﾊﾟｯﾄﾞ(右)入力時、右移動
		else if (GetJoypadInputState(PAD_INPUT_RIGHT) == 1)

		{
			MapPos.x = MapPos.x + 5.0;
		}

		// ﾊﾟｯﾄﾞ(上)入力時、跳躍
		if (GetJoypadInputState(PAD_INPUT_UP) == 1)
		{
			AnyFlag = 1;
			jmpPos = MapPos;
		}

		break;

	// 何らかのバグ
	default:

		break;

	}

	// 画面外に行かないようにする制御
	if ( MapPos.x < Size.x/2 )
	{
		MapPos.x = Size.x / 2;
	}
	if (MapPos.x > MapSize.x- Size.x / 2)
	{
		MapPos.x = MapSize.x- Size.x / 2;
	}


	// 跳躍ﾌﾗｸﾞが立っているとき
	if (AnyFlag == true)
	{
		// 跳躍山なり移動用2次関数
		MapPos.y = pow((sec-jmpCnt),2)/15+jmpPos.y-96;
		// 経過時間計測
		sec++;
		// もし、着地したら
		if (sec == jmpCnt)
		{
			// 跳躍ﾌﾗｸﾞ戻し
			AnyFlag = false;

			// 経過時間観測用変数初期化
			sec = 0;
		}
	}
	else
	{
		
	}

}

void player::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image, LAYER::PLAYER, 999));
}

// 攻撃制御関数
void player::attackCtl(void)
{

	// 射撃ﾌﾗｸﾞ管理
	if (shotFlag == false && CheckHitKey(KEY_INPUT_A))
	{
		shotPos = MapPos;

		shotFlag = true;
	}

	// 近接ﾌﾗｸﾞ管理
	if (atkFlag == false && CheckHitKey(KEY_INPUT_B))
	{
		shotPos = MapPos;
		atkFlag = true;
	}

	// 射撃制御関数呼び出し
	if (shotFlag == true)
	{
		shot();
	}

	// 近接制御関数呼び出し
	if ( atkFlag == true)
	{
		shot();
	}

}

// 近接関数
void player::attack(void)
{ 
	atkPos.x = atkPos.x + 0.1;
}

// 射撃関数
void player::shot(void)
{
	shotPos.x = shotPos.x + 3.0;

	if (shotPos.x >= lpSceneMng.ScreenSize.x || shotPos.x <= 0)
	{
		shotFlag = false;
	}
}

// player初期化
void player::Init(void)
{
	ptn = KeyBoard;

	jmpCnt = 40;

	sec = 0;

	AnyFlag = false;

	shotFlag = false;

	shotPos = { 0.0,0.0 };

	//LoadDivGraph("image/歩行ドットキャラ.png",12,3,4,32,32,plImage);
	Image = LoadGraph("image/test.png", true);

	dead = false;
}
