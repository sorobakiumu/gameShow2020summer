#pragma once
#include "../Enemy.h"
#include"../../Common/Vector2.h"
#include"../../player/player.h"
#include <memory>

class BaseEnemy;

using sharedEnemy = std::shared_ptr<BaseEnemy>;


class BaseEnemy
{
public:
	virtual void Draw(void) = 0;

	// À•Wæ“¾—pŠÖ”
	const Vec2double pos()const { return _pos; }

	const bool Dead()const { return _deadFlag; }

	virtual void UpDate(Vec2double pPos) = 0;
	BaseEnemy();
	virtual ~BaseEnemy();
protected:
	Vec2double _pos;
	bool _aliveflag;
	bool _deadFlag;
};

