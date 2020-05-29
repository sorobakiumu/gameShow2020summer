#include "shot.h"

// �ݽ�׸�
shot::shot()
{

}

// �w��t���ݽ�׸�
shot::shot(Vec2double pos, Vec2Int size , PLSTATE _state)
{
	MapPos = pos;			// ���W������

	startPos = pos;			// 

	size = size;			// ���ޏ�����

	moveState = _state;		// �i�s�����ݒ�

	ID = OBJ_ID::PLAYER;	// ��޼ު�đ����ݒ�

	Init();					// ���̑�������
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
		MapPos.x = MapPos.x - 3.0;

		if (MapPos.x - startPos.x == -1800)
		{
			return false;
		}

		break;

	case PLSTATE::WORKR:
		MapPos.x = MapPos.x + 3.0;
		
		if (MapPos.x - startPos.x == 1800)
		{
			return false;

		}

		break;


		break;

	default:
		break;
	}

	
	return true;

}

// player������
void shot::Init(void)
{
	Rad = 0;

	 
	
}

void shot::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, lpImageMng.GetMap("�e") , LAYER::PLAYER, 999));
}

void shot::UpDate()
{
}
