#pragma once
#include "player.h"
#include "../Common/Vector2.h"

class shot :
	public Obj
{
public:
	// 関数
	shot();												// ｺﾝｽﾄﾗｸﾀ
	shot(Vec2double pos, Vec2Int size, PLSTATE _state);	// 指定付きｺﾝｽﾄﾗｸﾀ
	~shot();
	bool shotMove(void);								// 攻撃制御
	void Init();									// 初期化

	void Draw();
	void UpDate() override;		// player更新用関数

	// 変数
	PLSTATE moveState;									// 状態格納変数

private:
	Vec2double startPos;

};

