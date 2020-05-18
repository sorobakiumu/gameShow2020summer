#pragma once
#include<memory>
#include "../Common/Vector2.h"
#include <vector>

enum class OBJ_ID
{
	PLAYER,
	ENEMY,
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

	const OBJ_ID GetID()const { return ID; }

	// 座標取得用関数
	const Vec2double GetPos()const { return Pos; }

	// ｻｲｽﾞ取得用関数
	const Vec2Int GetSize()const { return Size; }

	// 死亡確定用関数
	const bool Getdead()const { return dead; }

	void SetPos(Vec2double pos) { Pos = pos; }

	void Draw(int id);

	virtual void Draw(void) = 0;

	bool State(const STATE state);

	const STATE animKey(void) const;

	bool SetAnim(const STATE state, AnimVector& data);

	bool isAnimEnd(void);

	bool isAlive(void);



	virtual void UpDate() = 0;
protected:
	OBJ_ID ID;
	Vec2double Pos;
	Vec2Int Size;

	bool dead;
	bool alive;

private:

	//std::map<STATE , Anim

};

