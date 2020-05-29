#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../manager/SceneManage.h"
#include "../scene/GameScene.h"
#include "../manager/ImageManage.h"
#include "../manager/SEManage.h"


// ���쎯�ʍ\����
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

	player();								// �ݽ�׸�
	player(Vec2double pos, Vec2Int size);	// �w��t���ݽ�׸�
	~player();								// player���޽�׸�

	void UpDate() override;		// player�X�V�p�֐�
	//void shot(void);			// 
	void attack(void);			// 

	void Draw();				// 

	int plHP;					// ��ڲ԰HP����ϐ�			

protected:

	bool shotFlag;				// �����׸ޕϐ�
	bool atkFlag;				// �ߐ��׸ޕϐ�
	bool accelFlag;				// �����׸ޕϐ�


private:
	static player* sInstance;

	int Image[6];				// player�摜�i�[�ϐ�
	void attackCtl(void);		// 
	void Init(void);			// �������֐�

	int jmpCnt;					// ���􎞊ԕϐ�
	int sec;					// ����o�ߎ��ԕϐ�
	Vec2double jmpPos;			// ������W����ϐ�
	bool jmpFlag;				// �����׸ޕϐ�

	PLSTATE plstate;

	Ctl ptn;					// 

	int pushCtl[3];				// 

	int bulletImage;			// �ˌ��摜�i�[�ϐ�

	void accel(void);			// 

};

