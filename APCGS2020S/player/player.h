#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../scene/SceneManage.h"

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
	player();									// ｺﾝｽﾄﾗｸﾀ
	player(Vec2double pos, Vec2Int size);		// 指定付きｺﾝｽﾄﾗｸﾀ
	~player();									// playerのﾃﾞｽﾄﾗｸﾀ

	int jpCtlFlag;

private:

	void Update(void);

	void Init(void);							// 初期化関数

	int jmpFlg;
	int jmpCnt;
	int sec;

	Ctl ptn;
};

