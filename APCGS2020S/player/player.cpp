#include "player.h"
#include "DxLib.h"

// player�̺ݽ�׸�
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

	// ��ʊO�ɍs���Ȃ��悤�ɂ��鐧��
	if ( Pos.x <= 0 )
	{
		Pos.x = 0;
	}
	if (Pos.x >= lpSceneMng.ScreenSize.x)
	{
		Pos.x = lpSceneMng.ScreenSize.x;
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
	Draw();
}

void player::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(Pos, 1.0, 0.0, Image, LAYER::CHARA, 999));
}

// �U������֐�
void player::attackCtl(void)
{

	// �ˌ��׸ފǗ�
	if (shotFlag == false && CheckHitKey(KEY_INPUT_A))
	{
		shotPos = Pos;

		shotFlag = true;
	}

	// �ߐ��׸ފǗ�
	if (atkFlag == false && CheckHitKey(KEY_INPUT_B))
	{
		shotPos = Pos;
		atkFlag = true;
	}

	// �ˌ�����֐��Ăяo��
	if (shotFlag == true)
	{
		shot();
	}

	// �ߐڐ���֐��Ăяo��
	if ( atkFlag == true)
	{
		shot();
	}

}

// �ߐڊ֐�
void player::attack(void)
{ 
	atkPos.x = atkPos.x + 0.1;
}

// �ˌ��֐�
void player::shot(void)
{
	shotPos.x = shotPos.x + 3.0;

	if (shotPos.x >= lpSceneMng.ScreenSize.x || shotPos.x <= 0)
	{
		shotFlag = false;
	}
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

	//LoadDivGraph("image/���s�h�b�g�L����.png",12,3,4,32,32,plImage);
	Image = LoadGraph("image/test.png", true);

	dead = false;
}
