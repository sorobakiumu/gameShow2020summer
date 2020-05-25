#pragma once
#include "../../Obj/Obj.h"

#define lpCheckHit FuncCheckHit::GetInstance()

class FuncCheckHit
{
public:
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

	static void SetMap(Vec2Int size, std::vector<int> Map);

	static FuncCheckHit* sInstance;

	static std::vector<int> map;
private:
	FuncCheckHit();
	~FuncCheckHit();





	Vec2double plPos;
	Vec2Int plSize;
};

