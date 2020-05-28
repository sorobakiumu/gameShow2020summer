#pragma once
#include "player.h"
#include "../Common/Vector2.h"

class shot :
	public Obj
{
	// 関数
	shot();												// ｺﾝｽﾄﾗｸﾀ
	shot(Vec2double pos, Vec2Int size, PLSTATE _state);	// 指定付きｺﾝｽﾄﾗｸﾀ
	~shot();
	bool shotMove(void);								// 攻撃制御
	void Init(void);									// 初期化

	void Draw();

	// 変数
	PLSTATE plState;									// 状態格納変数

private:
	Vec2double startPos;

};

