#pragma once
#include "../Obj/Obj.h"

class player :
	public Obj
{
public:
	player();									// �ݽ�׸�
	player(Vec2double pos, Vec2Int size);		// �w��t���ݽ�׸�
	~player();									// player���޽�׸�


private:

	void Init(void);							// �������֐�


};

