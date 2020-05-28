#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../manager/SceneManage.h"
#include "../scene/GameScene.h"
#include "../manager/ImageManage.h"
#include "../manager/SEManage.h"


// ���쎯�ʍ\����
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
	player();								// �ݽ�׸�
	player(Vec2double pos, Vec2Int size);	// �w��t���ݽ�׸�
	~player();								// player���޽�׸�

	void UpDate() override;		// player�X�V�p�֐�
	void shot(void);			// 
	void attack(void);			// 
	Vec2double shotPos;			// 
	Vec2double atkPos;			// 

	void Draw();				// 

	int plHP;					// ��ڲ԰HP����ϐ�			

protected:

	bool shotFlag;				// �����׸ޕϐ�
	bool atkFlag;				// �ߐ��׸ޕϐ�
	bool accelFlag;				// �����׸ޕϐ�


private:

	int Image[6];				// player�摜�i�[�ϐ�
	void attackCtl(void);		// 
	void Init(void);			// �������֐�

	int jmpCnt;					// ���􎞊ԕϐ�
	int sec;					// ����o�ߎ��ԕϐ�
	Vec2double jmpPos;			// ������W����ϐ�
	bool jmpFlag;				// �����׸ޕϐ�

	Ctl ptn;					// 
	int pushCtl[3];				// 

	int bulletImage;			// �ˌ��摜�i�[�ϐ�

	void accel(void);			// 

};

