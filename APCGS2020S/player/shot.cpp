#include "shot.h"

// �ݽ�׸�
shot::shot()
{
	Init();					// ���̑�������
	moveState = PLSTATE::STOPR;

}

// �w��t���ݽ�׸�
shot::shot(Vec2double pos, Vec2Int size , PLSTATE _state)
{
	Init();					// ���̑�������

	MapPos = pos;			// ���W������

	startPos = pos;			// 

	size = size;			// ���ޏ�����

	moveState = _state;		// �i�s�����ݒ�

	ID = OBJ_ID::PLAYER;	// ��޼ު�đ����ݒ�

}

shot::~shot()
{
}




// �U������֐�
bool shot::shotMove(void)
{
	switch (moveState)
	{
	case PLSTATE::WORKL:
	
		// �e�̈ړ��m�F(��)
		MapPos.x = MapPos.x - 3.0;

		// 
		if (MapPos.x - startPos.x == -1800)
		{
			return false;
		}

		break;

	case PLSTATE::WORKR:
	
		// �e�̈ړ��m�F(�E)
		MapPos.x = MapPos.x + 3.0;
		
		// 
		if (MapPos.x - startPos.x == 1800)
		{
			return false;

		}

		break;

	default:
		break;
	}

	
	return true;

}

// shot������
void shot::Init()
{
	Rad = 0.0;

	moveState = PLSTATE::STOPR;
}

void shot::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, Rad, lpImageMng.GetMap("�e") , LAYER::PLAYER, 999));
}

void shot::UpDate()
{
	shotMove();

	Draw();
}
