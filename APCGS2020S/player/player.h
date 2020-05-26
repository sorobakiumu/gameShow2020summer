#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../manager/SceneManage.h"
#include "../scene/GameScene.h"
#include "../manager/ImageManage.h"

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
	Vec2double jmpPos;
	bool shotFlag;
	bool atkFlag;

	int ptn;
};

