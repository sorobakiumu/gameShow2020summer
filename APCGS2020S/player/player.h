#pragma once
#include "../Obj/Obj.h"

class player :
	public Obj
{
public:
	player();									// ｺﾝｽﾄﾗｸﾀ
	player(Vec2double pos, Vec2Int size);		// 指定付きｺﾝｽﾄﾗｸﾀ
	~player();									// playerのﾃﾞｽﾄﾗｸﾀ


private:

	void Init(void);							// 初期化関数


};

