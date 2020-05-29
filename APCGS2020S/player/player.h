#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../manager/SceneManage.h"
#include "../scene/GameScene.h"
#include "../manager/ImageManage.h"
#include "../manager/SEManage.h"


// 操作識別構造体
enum class Ctl
{
	KeyBoard,
	Pad,
	max

};

enum class PLSTATE
{
	STOPL,
	WORKL,
	JUMPL,
	STOPR,
	WORKR,
	JUMPR,
	MAX,
};

#define lpplayer player::GetInstance()

class player:
	public Obj
{
public:

	static player& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new player();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}

	player();								// ｺﾝｽﾄﾗｸﾀ
	player(Vec2double pos, Vec2Int size);	// 指定付きｺﾝｽﾄﾗｸﾀ
	~player();								// playerのﾃﾞｽﾄﾗｸﾀ

	void UpDate() override;		// player更新用関数
	//void shot(void);			// 
	void attack(void);			// 

	void Draw();				// 

	int plHP;					// ﾌﾟﾚｲﾔｰHP制御変数			

protected:

	bool shotFlag;				// ｼｮｯﾄﾌﾗｸﾞ変数
	bool atkFlag;				// 近接ﾌﾗｸﾞ変数
	bool accelFlag;				// 加速ﾌﾗｸﾞ変数


private:
	static player* sInstance;

	int Image[6];				// player画像格納変数
	void attackCtl(void);		// 
	void Init(void);			// 初期化関数

	int jmpCnt;					// 跳躍時間変数
	int sec;					// 跳躍経過時間変数
	Vec2double jmpPos;			// 跳躍座標制御変数
	bool jmpFlag;				// 跳躍ﾌﾗｸﾞ変数

	PLSTATE plstate;

	Ctl ptn;					// 

	int pushCtl[3];				// 

	int bulletImage;			// 射撃画像格納変数

	void accel(void);			// 

};

