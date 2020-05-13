#include "player.h"



// playerのコンストラクタ
player::player()
{
	// 初期化
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

void player::Init(void)
{


}
