#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../scene/SceneManage.h"
#include "../scene/GameScene.h"

// ���쎯�ʍ\����
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
	player();								// �ݽ�׸�
	player(Vec2double pos, Vec2Int size);	// �w��t���ݽ�׸�
	~player();								// player���޽�׸�

	void UpDate() override;;				// player�X�V�p�֐�
	int jpCtlFlag;							// ���������׸ޕϐ�


private:

	
	
	void Init(void);						// �������֐�

	int jmpFlg;								// ����J�n�ϐ�
	int jmpCnt;								// ���������׸ޕϐ�
	int sec;								// ���������׸ޕϐ�

	Ctl ptn;
};

