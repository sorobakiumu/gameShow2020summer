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
	MapPos = _pos;

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
			MapPos.x = MapPos.x - 5.0;
		}
		// �\����(�E)���͎��A�E�ړ�
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			MapPos.x = MapPos.x + 5.0;
		}
        
		// �\����(��)���͎��A����
		if (CheckHitKey(KEY_INPUT_UP) == 1 && AnyFlag == false)
		{
			AnyFlag = true;
			jmpPos = MapPos;
		}
		break;

	// �ް��߯��?�g�p��
	case Pad:

		// �߯��(��)���͎��A���ړ�
		if (GetJoypadInputState(PAD_INPUT_LEFT) == 1)
		{
			MapPos.x = MapPos.x - 5.0;
		}
		// �߯��(�E)���͎��A�E�ړ�
		else if (GetJoypadInputState(PAD_INPUT_RIGHT) == 1)

		{
			MapPos.x = MapPos.x + 5.0;
		}

		// �߯��(��)���͎��A����
		if (GetJoypadInputState(PAD_INPUT_UP) == 1)
		{
			AnyFlag = 1;
			jmpPos = MapPos;
		}

		break;

	// ���炩�̃o�O
	default:

		break;

	}

	// ��ʊO�ɍs���Ȃ��悤�ɂ��鐧��
	if ( MapPos.x < Size.x/2 )
	{
		MapPos.x = Size.x / 2;
	}
	if (MapPos.x > MapSize.x- Size.x / 2)
	{
		MapPos.x = MapSize.x- Size.x / 2;
	}


	// �����׸ނ������Ă���Ƃ�
	if (AnyFlag == true)
	{
		// ����R�Ȃ�ړ��p2���֐�
		MapPos.y = pow((sec-jmpCnt),2)/15+jmpPos.y-96;
		// �o�ߎ��Ԍv��
		sec++;
		// �����A���n������
		if (sec == jmpCnt)
		{
			// �����׸ޖ߂�
			AnyFlag = false;

			// �o�ߎ��Ԋϑ��p�ϐ�������
			sec = 0;
		}
	}
	else
	{
		
	}

}

void player::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image, LAYER::PLAYER, 999));
}

// �U������֐�
void player::attackCtl(void)
{

	// �ˌ��׸ފǗ�
	if (shotFlag == false && CheckHitKey(KEY_INPUT_A))
	{
		shotPos = MapPos;

		shotFlag = true;
	}

	// �ߐ��׸ފǗ�
	if (atkFlag == false && CheckHitKey(KEY_INPUT_B))
	{
		shotPos = MapPos;
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

	jmpCnt = 40;

	sec = 0;

	AnyFlag = false;

	shotFlag = false;

	shotPos = { 0.0,0.0 };

	//LoadDivGraph("image/���s�h�b�g�L����.png",12,3,4,32,32,plImage);
	Image = LoadGraph("image/test.png", true);

	dead = false;
}
