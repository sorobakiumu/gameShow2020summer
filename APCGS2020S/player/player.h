#pragma once
#include "..\Common\Vector2.h"
#include "../Obj/Obj.h"
#include "../scene/SceneManage.h"

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
	player();									// �ݽ�׸�
	player(Vec2double pos, Vec2Int size);		// �w��t���ݽ�׸�
	~player();									// player���޽�׸�

	int jpCtlFlag;

private:

	void Update(void);

	void Init(void);							// �������֐�

	int jmpFlg;
	int jmpCnt;
	int sec;

	Ctl ptn;
};

