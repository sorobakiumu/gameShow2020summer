#pragma once
#include "../Obj/Obj.h"
#include <vector>
#include "../Common/Vector2.h"


#define lpEnemy Enemy::GetInstance()


enum class ENEMY_ID
{
	WOLF,
	GHOST,
	MAN,
	BLACK,
	BURST,
	BAZE,
	PIT,
	BOSS,
	RARE,
	MAX
};

class Enemy :
	public Obj
{
public:
	Enemy(ENEMY_ID enemyId);
	~Enemy();
	void UpDate();
private:
	static Enemy* sInstance;		//���I�ɍ�邽�߂ɁA�|�C���^�[�ŁA���̂�������̂����
	ENEMY_ID _enemyID;

	void wolff();
	void ghost();
	void man();
	void black();
	void burst();
	void baze();
	void pit();
	void boss();
	void rare();

};

