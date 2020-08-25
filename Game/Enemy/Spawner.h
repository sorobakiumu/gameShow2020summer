#pragma once
#include <memory>
#include <list>
#include "../../Geometry.h"
class Camera;
class Enemy;
/// <summary>
/// �G��������N���X
/// </summary>
class EnemyManager;
class Spawner
{
protected:
	Position2f pos_;//��ʓ��ɃX�|�[�i�[�����邩�ǂ����̔��肪�K�v�Ȃ��ߍ��W������
	std::unique_ptr<Enemy> prototype_;//�v���g�^�C�v
	std::shared_ptr<EnemyManager>& enemyManager;
	std::shared_ptr<Camera> camera_;
	virtual Enemy* CreatCloan()final;

public:
	Spawner(const Position2f& pos, Enemy* prototype, std::shared_ptr<EnemyManager>& em, std::shared_ptr<Camera> c);
	virtual ~Spawner() = default;
	/// <summary>
	/// �������Ƀ��X�g�ɕ��荞�ނ������ɃV�F�A�|�C���^���Ԃ�
	/// </summary>
	/// <returns></returns>
//	virtual std::shared_ptr<Enemy> Spawn() = 0;
	/// <summary>
	/// ���Ԃ��Ƃ̔����Ȃǂ��K�v�Ȃ��ߖ��t���[���X�V���s��
	/// </summary>
	virtual void Update() = 0;
};
