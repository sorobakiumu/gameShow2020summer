#pragma once
#include <vector>
#include "../Common/Vector2.h"
#include <map>


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

class Enemy
{
public:
	Enemy(ENEMY_ID enemyId);
	~Enemy();
	void UpDate();
private:
	static Enemy* sInstance;		//動的に作るために、ポインターで、実体が入るものを作る
	ENEMY_ID _enemyID;

	bool flag;
	Vec2double pos;

	std::map<ENEMY_ID, std::vector<int>> enemyImage;

	void wolff();
	void ghost();
	void man();
	void black();
	void burst();
	void baze();
	void boss();
	void rare();

};

