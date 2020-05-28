#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../manager/SceneManage.h"
#include "../scene/GameScene.h"
#include "../manager/ImageManage.h"
#include "../manager/SEManage.h"


// 操作識別構造体
enum Ctl
{
	KeyBoard,
	Pad,
	max

};

enum PLSTATE
{
	STOPL,
	WORKL,
	JUMPL,
	STOPR,
	WORKR,
	JUMPR,
	MAX,
};

class player :
	public Obj
{
public:
	player();								// ｺﾝｽﾄﾗｸﾀ
	player(Vec2double pos, Vec2Int size);	// 指定付きｺﾝｽﾄﾗｸﾀ
	~player();								// playerのﾃﾞｽﾄﾗｸﾀ

	void UpDate() override;		// player更新用関数
	void shot(void);			// 
	void attack(void);			// 
	Vec2double shotPos;			// 
	Vec2double atkPos;			// 

	void Draw();				// 

	int plHP;					// ﾌﾟﾚｲﾔｰHP制御変数			

private:
	int Image[6];				// 
	void attackCtl(void);		// 
	void Init(void);			// 初期化関数

	int jmpCnt;					// 跳躍制御ﾌﾗｸﾞ変数
	int sec;					// 跳躍制御ﾌﾗｸﾞ変数
	Vec2double jmpPos;			// 
	bool jmpFlag;				// 
	bool shotFlag;				// 
	bool atkFlag;				// 
	bool accelFlag;				// 

	int ptn;					// 
	int pushCtl[3];				// 

	int bulletImage;			// 射撃画像格納変数

	void accel(void);			// 

};

