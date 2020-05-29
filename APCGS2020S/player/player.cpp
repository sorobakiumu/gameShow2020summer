#include "player.h"
#include "DxLib.h"
#include "shot.h"

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
		if (CheckHitKey(KEY_INPUT_UP) == 1 && AnyFlag == false && jmpFlag == false)
		{
			jmpFlag = true;
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
		if (GetJoypadInputState(PAD_INPUT_UP) == 1 && AnyFlag == false && jmpFlag == false)
		{
			jmpFlag = true;
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
	if (jmpFlag == true && AnyFlag == false)
	{
		// ����R�Ȃ�ړ��p2���֐�
		MapPos.y = pow((sec-jmpCnt),2)/15+jmpPos.y-96;
		// �o�ߎ��Ԍv��
		sec++;
		// �����A���n������
		if (sec == jmpCnt)
		{
			jmpFlag = false;
			AnyFlag = true;
			sec = 0;
		}
	}
	else
	{
		
	}

	// �U���֘A�֐��Ăяo��
	attackCtl();

	//// �����p���֐��Ǘ�
	//if (shotFlag == false && CheckHitKey(KEY_INPUT_D) != pushCtl[0] && CheckHitKey(KEY_INPUT_D) == 1)
	//{
	//	shotPos = MapPos;

	//	shotFlag = true;
	//}


}

// �`��֐�
void player::Draw()
{
	lpSceneMng.addDrawQue(std::make_tuple(MapPos, 1.0, 0.0, Image[0], LAYER::PLAYER, 999));
	
	if (shotFlag == true)
	{
	//	lpSceneMng.addDrawQue(std::make_tuple(shotPos, 1.0, 0.0, bulletImage, LAYER::PLAYER, 999));
	}
}

// �U������֐�
void player::attackCtl(void)
{

	// �ˌ��׸ފǗ�
	if (shotFlag == false && CheckHitKey(KEY_INPUT_D) != pushCtl[0] && CheckHitKey(KEY_INPUT_D) == 1)
	{

		shotFlag = true;
	}

	// �ߐ��׸ފǗ�
	if (atkFlag == false && CheckHitKey(KEY_INPUT_S) != pushCtl[1] && CheckHitKey(KEY_INPUT_S) == 1)
	{
		//atkPos = MapPos;
		atkFlag = true;
	}

	

	// �ˌ�����֐��Ăяo��
	if (shotFlag == true)
	{
		new shot( MapPos , MapSize , plstate);
	}

	// �ߐڐ���֐��Ăяo��
	if ( atkFlag == true)
	{
	}

}

// �ߐڊ֐�
void player::attack(void)
{ 
	//atkPos.x = atkPos.x + 0.1;
}


// �����p�������֐�
void player::accel(void)
{


}


// player������
void player::Init(void)
{
	Rad = 0;

	ptn = KeyBoard;

	jmpCnt = 40;

	sec = 0;

	AnyFlag = false;
	jmpFlag = false;
	shotFlag = false;

	//shotPos = { 0.0,0.0 };

	LoadDivGraph("image/test.png",6,3,2,32,32,Image);
	//Image = LoadGraph("image/test.png", true);

	bulletImage = LoadGraph("image/�e.png");

	for (int i = 0; i < 3; i++)
	{
		pushCtl[i] = 0;
	}

	StopSoundMem(lpSEMng.loadBGM("BGM"));
	dead = false;
}

