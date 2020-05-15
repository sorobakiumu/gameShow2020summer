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
	player();									// ºİ½Ä×¸À
	player(Vec2double pos, Vec2Int size);		// w’è•t‚«ºİ½Ä×¸À
	~player();									// player‚ÌÃŞ½Ä×¸À

	int jpCtlFlag;

private:

	void Update(void);

	void Init(void);							// ‰Šú‰»ŠÖ”

	int jmpFlg;
	int jmpCnt;
	int sec;

	Ctl ptn;
};

