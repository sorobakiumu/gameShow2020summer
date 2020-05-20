#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../scene/SceneManage.h"
#include "../scene/GameScene.h"
#include "../scene/ImageManage.h"

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
	player(Vec2double pos, Vec2Int size,Vec2Int MSize);	// 指定付きｺﾝｽﾄﾗｸﾀ
	~player();								// playerのﾃﾞｽﾄﾗｸﾀ

	void UpDate() override;				// player更新用関数

	void shot(void);
	void attack(void);
	Vec2double shotPos;
	Vec2double atkPos;

	void Draw();

	int plImage[12];
private:
	int Image;
	
	void attackCtl(void);
	void Init(void);						// 初期化関数

	int jmpCnt;								// 跳躍制御ﾌﾗｸﾞ変数
	int sec;								// 跳躍制御ﾌﾗｸﾞ変数
	bool jmpFlg;							// 跳躍開始変数
	bool jpCtlFlag;							// 跳躍制御ﾌﾗｸﾞ変数
	bool shotFlag;
	bool atkFlag;

	int ptn;
};

