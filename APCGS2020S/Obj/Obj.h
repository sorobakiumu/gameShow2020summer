#pragma once
#include "../Common/Vector2.h"
#include <vector>
#include <string>
#include <memory>
#include <map>
#include "../scene/LAYER.h"

#include"../manager/CheckHitManage.h"


#define CHIP_SIZE 32

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

	// ID�擾�p�֐�
	const OBJ_ID GetID()const { return ID; }

	// ���W�擾�p�֐�
	const Vec2double GetPos()const { return MapPos; }

	// ���ގ擾�p�֐�
	const Vec2Int GetSize()const { return Size; }

	// ���S�m��p�֐�
	const bool Getdead()const { return dead; }

	// �����擾�p�֐�
	bool GetAlive(void) { return alive; };

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
protected:
	OBJ_ID ID;
	Vec2double MapPos;
	Vec2Int Size;

	// ���S�ɏ����Ă������𔻒f����
	bool dead;
	
	// �����Ă��邩�ǂ����𔻒f����
	bool alive;

	int _zOrder;											// �`�悷�鏇��(���s�AZ��)���w��
	double _rad;

	// ���S�ɍ폜�\�������ʂ���֐�
	bool Destroyproc(void);

private:

	// ��Ұ��݂̍\�����Ǘ�����STL
	std::map<STATE, AnimVector> _animMap;

	STATE _state = STATE::NORMAL;
	
	// ��Ұ��݂̉��R�}�ڂ�
	unsigned int _animFlam;									
	
	// ���񃋁[�v������
	unsigned int _animCnt;								

};

