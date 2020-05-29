#pragma once
#include "../Common/Vector2.h"
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "../scene/LAYER.h"

#include"../manager/CheckHitManage.h"

#define CHIP_SIZE 32

enum class GIMMICK_ID
{
	NON,
	LIFT,
	FALL_LIFT,
	NEEDLE,
	FALLNEEDLE,
	CANON,
	BULLET,
	GENERATOR,
	MAX,
};

enum class OBJ_ID
{
	PLAYER,
	ENEMY,
	FRY_ENEMY,
	ITEM,
	GIMMICK,
	MAX,
};


// 状態管理enum class
enum class STATE
{
	NORMAL,			// 通常状態
	EX,				// 特殊状態
	DEATH,			// 死亡状態
	MAX
};

class Obj;

// 複数個所でﾎﾟｲﾝﾀｰ参照するための代物
using SharedObj = std::shared_ptr<Obj>;

using AnimVector = std::vector<std::pair<int, unsigned int>>;

class Obj
{
public:
	Obj();
	virtual ~Obj();

	virtual void Draw(void) = 0;

	// ID取得用関数
	const OBJ_ID GetID()const { return ID; }

	// 座標取得用関数
	const Vec2double GetPos()const { return MapPos; }

	// ｻｲｽﾞ取得用関数
	const Vec2Int GetSize()const { return Size; }

	// 死亡確定用関数
	const bool Getdead()const { return dead; }
	void SetDead(bool num) { dead = num; }

	void SetPos(Vec2double pos) { MapPos = pos; }


	// ｱﾆﾒｰｼｮﾝ抜きの描画を行う関数
	void Draw(Vec2double pos, int id  );

	// ｱﾆﾒｰｼｮﾝ変更関数
	bool State(const STATE state);

	// 現在の状態を取得する
	const STATE animKey(void) const;

	// ID毎のｱﾆﾒｰｼｮﾝ番号とｱﾆﾒｰｼｮﾝﾌﾚｰﾑ数を譲渡
	bool SetAnim(const STATE state, AnimVector& data);

	// 死亡時ｱﾆﾒｰｼｮﾝ終了確認用関数
	bool isAnimEnd(void);

	// 生存ｽﾃｰﾀｽ変更用関数
	virtual bool SetAlive(bool alive);		// 生存ｽﾃｰﾀｽ変更用関数

	virtual void UpDate() = 0;

	// Obj毎の各種フラグ関連
	bool CheckFlag() { return AnyFlag; }
	void SetFlag(bool tmp) { AnyFlag = tmp; }

	GIMMICK_ID GetGID() { return G_ID; }

	double GetRad() { return Rad; }
protected:
	OBJ_ID ID;
	Vec2double MapPos;
	Vec2Int Size;

	double Rad;
	// 完全に消していいかを判断する
	bool dead;
	
	// 生きているかどうかを判断する
	bool alive;

	int _zOrder;											// 描画する順番(奥行、Z軸)を指定

	// 完全に削除可能かを識別する関数
	bool Destroyproc(void);

	bool AnyFlag;

	GIMMICK_ID G_ID;
private:

	// ｱﾆﾒｰｼｮﾝの構造を管理するSTL
	std::map<STATE, AnimVector> _animMap;

	STATE _state = STATE::NORMAL;
	
	// ｱﾆﾒｰｼｮﾝの何コマ目か
	unsigned int _animFlam;									
	
	// 何回ループしたか
	unsigned int _animCnt;								

};

