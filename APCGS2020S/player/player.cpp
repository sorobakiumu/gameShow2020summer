#include "player.h"
#include "DxLib.h"
#include "shot.h"

player* player::sInstance = nullptr;

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
	case Ctl::KeyBoard:

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
		if (CheckHitKey(KEY_INPUT_UP) == 1 && AnyFlag == false && jmpFlag == false)
		{
			jmpFlag = true;
			jmpPos = MapPos;
		}
		break;

	// ｹﾞｰﾑﾊﾟｯﾄﾞ?使用時
	case Ctl::Pad:

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
		if (GetJoypadInputState(PAD_INPUT_UP) == 1 && AnyFlag == false && jmpFlag == false)
		{
			jmpFlag = true;
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
	if (jmpFlag == true && AnyFlag == false)
	{
		// 跳躍山なり移動用2次関数
		MapPos.y = pow((sec-jmpCnt),2)/15+jmpPos.y-96;
		// 経過時間計測
		sec++;
		// もし、着地したら
		if (sec == jmpCnt)
		{
			jmpFlag = false;
			AnyFlag = true;
			sec = 0;
		}
	}
	else
	{
		
	}

	// 攻撃関連関数呼び出し
	attackCtl();

	//// 加速術式関数管理
	//if (shotFlag == false && CheckHitKey(KEY_INPUT_D) != pushCtl[0] && CheckHitKey(KEY_INPUT_D) == 1)
	//{
	//	shotPos = MapPos;

	//	shotFlag = true;
	//}


}

// 描画関数
void player::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image[0], LAYER::PLAYER, 999));
	
	if (shotFlag == true)
	{
	//	lpSceneMng.addDrawQue(std::make_tuple(shotPos, 1.0, 0.0, bulletImage, LAYER::PLAYER, 999));
	}
}

// 攻撃制御関数
void player::attackCtl(void)
{

	// 射撃ﾌﾗｸﾞ管理
	if (shotFlag == false && CheckHitKey(KEY_INPUT_D) != pushCtl[0] && CheckHitKey(KEY_INPUT_D) == 1)
	{
		new shot(MapPos, MapSize, plstate);

		shotFlag = true;
	}

	// 近接ﾌﾗｸﾞ管理
	if (atkFlag == false && CheckHitKey(KEY_INPUT_S) != pushCtl[1] && CheckHitKey(KEY_INPUT_S) == 1)
	{
		//atkPos = MapPos;
		atkFlag = true;
	}

	

	// 射撃制御関数呼び出し
	if (shotFlag == true)
	{
		//shot::UpDate();
	}

	// 近接制御関数呼び出し
	if ( atkFlag == true)
	{
	}

}

// 近接関数
void player::attack(void)
{ 
	//atkPos.x = atkPos.x + 0.1;
}


// 加速術式実装関数
void player::accel(void)
{


}


// player初期化
void player::Init(void)
{
	Rad = 0;

	ptn = Ctl::KeyBoard;

	jmpCnt = 40;

	sec = 0;

	AnyFlag = false;
	jmpFlag = false;
	shotFlag = false;

	//shotPos = { 0.0,0.0 };

	LoadDivGraph("image/test.png",6,3,2,32,32,Image);
	//Image = LoadGraph("image/test.png", true);

	bulletImage = LoadGraph("image/弾.png");

	for (int i = 0; i < 3; i++)
	{
		pushCtl[i] = 0;
	}

	StopSoundMem(lpSEMng.loadBGM("BGM"));
	dead = false;
}

