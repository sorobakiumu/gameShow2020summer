#pragma once
#include <vector>
#include "../Common/Vector2.h"
#include <map>
#include "../Obj/Obj.h"


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

class Enemy:
public Obj
	{
		public:
		Enemy(ENEMY_ID enemyId);
		~Enemy();
		void UpDate();
		static bool initFlag;

		private:

		ENEMY_ID _enemyID;
		void EnemyInit();
		bool flag;

		int animCnt;
		int frmCnt;

		void Draw();

		std::map<ENEMY_ID, std::vector<int>> enemyImage;

		Vec2double pitCnt[4];

		void wolff();
		void ghost();
		void man();
		void black();
		void burst();
		void baze();
		void boss();
		void rare();
		void pit(int num);
};

