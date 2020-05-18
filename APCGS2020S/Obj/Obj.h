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


// ��ԊǗ�enum class
enum class STATE
{
	NORMAL,			// �ʏ���
	EX,				// ������
	DEATH,			// ���S���
	MAX
};

class Obj;

// ���������߲����Q�Ƃ��邽�߂̑㕨
using SharedObj = std::shared_ptr<Obj>;

using AnimVector = std::vector<std::pair<int, unsigned int>>;

class Obj
{
public:
	Obj();
	virtual ~Obj();

	virtual void Draw(void) = 0;

	const OBJ_ID GetID()const { return ID; }

	// ���W�擾�p�֐�
	const Vec2double GetPos()const { return Pos; }

	// ���ގ擾�p�֐�
	const Vec2Int GetSize()const { return Size; }

	// ���S�m��p�֐�
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

