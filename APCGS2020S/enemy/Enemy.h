#pragma once
#include <vector>
#include "../Common/Vector2.h"
#include <memory>
#include <map>
#include "../Obj/Obj.h"
//#include "enemy/BaseEnemy.h"
//#include <Windows.h>


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
		static Enemy& GetInstance(void)
		{
			Create();
			return *sInstance;
		}

		static void Create()
		{
			if (sInstance == nullptr)
			{
				sInstance = new Enemy();
			}
		}

		static void Destroy()
		{
			if (sInstance != nullptr)
			{
				delete sInstance;
			}
			sInstance = nullptr;
		}



	std::map<ENEMY_ID, std::vector<int>> enemyImage;

	//Obj UpDate(Vec2double pPos);

private:
	Enemy();
	~Enemy();
	//std::vector<sharedEnemy> _enemylist;
	static Enemy* sInstance;
	ENEMY_ID _enemyID;
};

