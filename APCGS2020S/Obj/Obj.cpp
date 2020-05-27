#include "Obj.h"
#include "../manager/SceneManage.h"

Obj::Obj()
{
	alive = true;
	dead = false;
	_animFlam = 0;
	_animCnt = 0;
	_zOrder = 0;
	_state = STATE::NORMAL;
	_rad = 0.0;
	ID = OBJ_ID::MAX;
	G_ID = GIMMICK_ID::NON;
}

Obj::~Obj()
{

}

// �ꖇ�G(��Ұ��݂Ȃ�)��`�悷��֐�
void Obj::Draw(Vec2double pos, int id)
{
	lpSceneMng.addDrawQue({ pos , _rad , _zOrder, id , LAYER::MAP , 900 });
}

// ��Ұ��ݕύX�֐�
bool Obj::State(const STATE state)
{
	// ���������Ұ��݂��ݒ肳��ĂȂ������炳��Ȃ�o�C�o�C
	if (_animMap.find(state) == _animMap.end())
	{
		return false;
	}

	// ��Ұ��݂��؂�ւ�������A��Ұ��݊֘A������������
	if (_state != state)
	{
		_animFlam = 0;
		_animCnt = 0;
	}

	// ��Ұ��݂�؂�ւ���
	_state = state;

	return true;
}

// ���݂̏�Ԃ��擾����
const STATE Obj::animKey(void) const
{
	return _state;
}

// ID���̱�Ұ��ݔԍ��Ʊ�Ұ����ڰт����n
bool Obj::SetAnim(const STATE state, AnimVector& data)
{
	// animMap��AnimVector��Ԃ�
	return (_animMap.try_emplace(state, std::move(data))).second;
}

// ���S����Ұ��ݏI���\���ǂ��������ʂ���֐�
bool Obj::isAnimEnd(void)
{
	// ���S���u1(�`��\��̉摜�����݂��Ă��邩�̊m�F)
	if (_animMap.find(_state) == _animMap.end())
	{
		return true;
	}

	// ���S���u2(�`��\��̉摜���ϐ��𒴂��Ă��Ȃ����̊m�F)
	if ((_animMap[_state].size() <= _animFlam) || (_animFlam < 0))
	{
		return true;
	}

	// ��Ұ��݂��I�������ꍇtrue��Ԃ�
	if (_animMap[_state][_animFlam].first == -1)
	{
		return true;

	}
	else   // �����łȂ����false��Ԃ�
	{
		return false;
	}
}

// �����ð���ύX�p�֐�
bool Obj::SetAlive(bool _alive)
{
	alive = _alive;
	if (!alive)
	{
		State(STATE::DEATH);
	}

	return true;
}

// ���S�ɍ폜�\�������ʂ���֐�
bool Obj::Destroyproc(void)
{
	// �����Ă��牽�����Ȃ�
	if (alive)
	{
		return false;
	}

	// ����łāA���±�Ұ��݂����S�I�����Ă������
	if (isAnimEnd())
	{
		dead = true;
	}

	return true;
}
