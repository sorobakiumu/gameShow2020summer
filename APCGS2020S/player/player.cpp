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

player::~player()
{

}


void player::Update(void)
{

	switch (ptn)
	{
	case KeyBoard:

		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Pos.x = Pos.x - 5.0;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Pos.x = Pos.x + 5.0;
		}
				 
		if (CheckHitKey(KEY_INPUT_UP) == 1 && jmpFlg == 0)
		{
			jpCtlFlag = 1;
		}
		break;

	case Pad:

		break;

	default:

		break;

	}


	if (jpCtlFlag == 1)
	{
		Pos.y = pow((sec - 180), 2) * (60/180) + lpSceneMng.ScreenSize.y - Size.y;

		sec++;
	}


}

void player::Init(void)
{
	sec = 0;
	jmpFlg = 0;
	jmpCnt = 180;
	jpCtlFlag = 0;
}
