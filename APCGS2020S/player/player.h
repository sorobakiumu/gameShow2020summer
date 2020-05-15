#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../scene/SceneManage.h"
#include "../scene/GameScene.h"

// 操作識別構造体
enum Ctl
{
	KeyBoard,
	Pad,
	max

};

class player :
	public Obj
{
public:
	player();								// ｺﾝｽﾄﾗｸﾀ
	player(Vec2double pos, Vec2Int size);	// 指定付きｺﾝｽﾄﾗｸﾀ
	~player();								// playerのﾃﾞｽﾄﾗｸﾀ

	void UpDate() override;;				// player更新用関数
	int jpCtlFlag;							// 跳躍制御ﾌﾗｸﾞ変数


private:

	
	
	void Init(void);						// 初期化関数

	int jmpFlg;								// 跳躍開始変数
	int jmpCnt;								// 跳躍制御ﾌﾗｸﾞ変数
	int sec;								// 跳躍制御ﾌﾗｸﾞ変数

	Ctl ptn;
};

