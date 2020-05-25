#pragma once
#include "../../Obj/Obj.h"

#define lpCheckHit FuncCheckHit::GetInstance()

struct FuncCheckHit
{
	bool CheckHit(Vec2double pos,Vec2Int size);

	static FuncCheckHit& GetInstance(void)
	{
		Create();
		return *sInstance;
	}
	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new FuncCheckHit();
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

	std::vector<int> map;
private:
	FuncCheckHit();
	~FuncCheckHit();

	static FuncCheckHit* sInstance;

	Vec2double plPos;
	Vec2Int plSize;
};

