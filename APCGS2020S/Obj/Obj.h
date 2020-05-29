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

	// ID�擾�p�֐�
	const OBJ_ID GetID()const { return ID; }

	// ���W�擾�p�֐�
	const Vec2double GetPos()const { return MapPos; }

	// ���ގ擾�p�֐�
	const Vec2Int GetSize()const { return Size; }

	// ���S�m��p�֐�
	const bool Getdead()const { return dead; }
	void SetDead(bool num) { dead = num; }

	void SetPos(Vec2double pos) { MapPos = pos; }


	// ��Ұ��ݔ����̕`����s���֐�
	void Draw(Vec2double pos, int id  );

	// ��Ұ��ݕύX�֐�
	bool State(const STATE state);

	// ���݂̏�Ԃ��擾����
	const STATE animKey(void) const;

	// ID���̱�Ұ��ݔԍ��Ʊ�Ұ����ڰѐ������n
	bool SetAnim(const STATE state, AnimVector& data);

	// ���S����Ұ��ݏI���m�F�p�֐�
	bool isAnimEnd(void);

	// �����ð���ύX�p�֐�
	virtual bool SetAlive(bool alive);		// �����ð���ύX�p�֐�

	virtual void UpDate() = 0;

	// Obj���̊e��t���O�֘A
	bool CheckFlag() { return AnyFlag; }
	void SetFlag(bool tmp) { AnyFlag = tmp; }

	GIMMICK_ID GetGID() { return G_ID; }

	double GetRad() { return Rad; }
protected:
	OBJ_ID ID;
	Vec2double MapPos;
	Vec2Int Size;

	double Rad;
	// ���S�ɏ����Ă������𔻒f����
	bool dead;
	
	// �����Ă��邩�ǂ����𔻒f����
	bool alive;

	int _zOrder;											// �`�悷�鏇��(���s�AZ��)���w��

	// ���S�ɍ폜�\�������ʂ���֐�
	bool Destroyproc(void);

	bool AnyFlag;

	GIMMICK_ID G_ID;
private:

	// ��Ұ��݂̍\�����Ǘ�����STL
	std::map<STATE, AnimVector> _animMap;

	STATE _state = STATE::NORMAL;
	
	// ��Ұ��݂̉��R�}�ڂ�
	unsigned int _animFlam;									
	
	// ���񃋁[�v������
	unsigned int _animCnt;								

};

