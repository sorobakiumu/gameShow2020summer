#include "player.h"



// player�̃R���X�g���N�^
player::player()
{
	// ������
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

void player::Init(void)
{


}
