#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../scene/SceneManage.h"
#include "../scene/GameScene.h"
#include "../scene/ImageManage.h"

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
	player(Vec2double pos, Vec2Int size,Vec2Int MSize);	// �w��t���ݽ�׸�
	~player();								// player���޽�׸�

	void UpDate() override;				// player�X�V�p�֐�

	void shot(void);
	void attack(void);
	Vec2double shotPos;
	Vec2double atkPos;

	void Draw();

	int plImage[12];
private:
	int Image;
	
	void attackCtl(void);
	void Init(void);						// �������֐�

	int jmpCnt;								// ���������׸ޕϐ�
	int sec;								// ���������׸ޕϐ�
	bool jmpFlg;							// ����J�n�ϐ�
	bool jpCtlFlag;							// ���������׸ޕϐ�
	bool shotFlag;
	bool atkFlag;

	int ptn;
};

