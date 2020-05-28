#pragma once
#include "player.h"
#include "../Common/Vector2.h"

class shot :
	public Obj
{
	// �֐�
	shot();												// �ݽ�׸�
	shot(Vec2double pos, Vec2Int size, PLSTATE _state);	// �w��t���ݽ�׸�
	~shot();
	bool shotMove(void);								// �U������
	void Init(void);									// ������

	void Draw();

	// �ϐ�
	PLSTATE plState;									// ��Ԋi�[�ϐ�

private:
	Vec2double startPos;

};

