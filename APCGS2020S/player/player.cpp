#include "player.h"
#include "DxLib.h"

// player�̃R���X�g���N�^
player::player()
{
	Init();
}

// player�̏������W��size��ݒ�
player::player(Vec2double _pos, Vec2Int _size)
{
	// player�̏������W��size��ݒ�
	Pos = _pos;

	// ���ޑ��
	Size = _size;

	// �Ώێ��ʕt�^
	ID = OBJ_ID::PLAYER;

	// ������
	Init();
}

// player���޽�׸�
player::~player()
{

}

// ��ڲ԰���̍X�V
void player::UpDate()
{
	// ������@�ɂ���ĕς��܂�
	switch (ptn)
	{
	// ���ް�ގg�p��
	case KeyBoard:

		// �\����(��)���͎��A���ړ�
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Pos.x = Pos.x - 5.0;
		}
		// �\����(�E)���͎��A�E�ړ�
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Pos.x = Pos.x + 5.0;
		}

		// �\����(��)���͎��A����
		if (CheckHitKey(KEY_INPUT_UP) == 1 && jmpFlg == 0)
		{
			jpCtlFlag = 1;
		}
		break;

	// �ް��߯��?�g�p��
	case Pad:

		// �߯��(��)���͎��A���ړ�
		if (GetJoypadInputState(PAD_INPUT_LEFT) == 1)
		{
			Pos.x = Pos.x - 5.0;
		}
		// �߯��(�E)���͎��A�E�ړ�
		else if (GetJoypadInputState(PAD_INPUT_RIGHT) == 1)

		{
			Pos.x = Pos.x + 5.0;
		}

		// �߯��(��)���͎��A����
		if (GetJoypadInputState(PAD_INPUT_UP) == 1)
		{
			jpCtlFlag = 1;
		}

		break;

	// ���炩�̃o�O
	default:

		break;

	}

	// �����׸ނ������Ă���Ƃ�
	if (jpCtlFlag == 1)
	{
		// ����R�Ȃ�ړ��p2���֐�
		Pos.y = pow((sec - jmpCnt), 2) * (64 / jmpCnt) + lpSceneMng.ScreenSize.y - Size.y;

		// �o�ߎ��Ԍv��
		sec++;

		// �����A���n������
		if (Pos.y >= lpSceneMng.ScreenSize.y )
		{
			// �߂荞�܂Ȃ��悤�ɍĒ���
			Pos.y = lpSceneMng.ScreenSize.y;
			
			// �����׸ޖ߂�
			jpCtlFlag = 0;

			// �o�ߎ��Ԋϑ��p�ϐ�������
			sec = 0;
		}
	}

}


// �U������֐�
void player::attack(void)
{ 
	if (shotFlag == false && CheckHitKey(KEY_INPUT_A))
	{
		shotFlag = true;
	}

	if (shotFlag == true)
	{
		shotPos = Pos;
		shot();
	}

}


void player::shot(void)
{
	shotPos.x = shotPos.x + 6.0;
}


// player������
void player::Init(void)
{
	ptn = KeyBoard;

	sec = 0;
	jmpCnt = 180;
	jmpFlg = false;
	jpCtlFlag = false;
	shotFlag = false;
	shotPos = { 0.0,0.0 };

}
