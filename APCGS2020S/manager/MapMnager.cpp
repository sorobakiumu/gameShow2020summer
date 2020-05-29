#include "MapMnager.h"

MapMnager* MapMnager::sInstance = nullptr;

Vec2double MapMnager::HitCheck(Vec2double pos, Vec2Int size, int Cnt)
{
	if (Cnt >= 20)
	{
		return pos;
	}
	bool Check[4] = { false,false,false,false };
	if (Map[static_cast<int>((pos.y - size.y / 2) / 32)][static_cast<int>((pos.x - size.x / 2) / 32)] > 0)
	{
		Check[0] = true;
	}
	if (Map[static_cast<int>((pos.y - size.y / 2) / 32)][static_cast<int>((pos.x + size.x / 2) / 32)] > 0)
	{
		Check[1] = true;
	}
	if (Map[static_cast<int>((pos.y + size.y / 2) / 32)][static_cast<int>((pos.x - size.x / 2) / 32)] > 0)
	{
		Check[2] = true;
	}
	if (Map[static_cast<int>((pos.y + size.y / 2) / 32)][static_cast<int>((pos.x + size.x / 2) / 32)] > 0)
	{
		Check[3] = true;
	}

	// 4ã˜ÇÃèÛë‘Çälìæ(ìñÇΩÇ¡ÇƒÇÈÇ©Ç«Ç§Ç©)
	if (Check[0] == true && Check[2] == true)
	{
		return HitCheck({ pos.x + 1,pos.y }, size, Cnt + 1);
	}
	else if (Check[1] == true && Check[3] == true)
	{
		return HitCheck({ pos.x - 1,pos.y }, size, Cnt + 1);
	}

	if (Check[0] == true || Check[1] == true)
	{
		return HitCheck({ pos.x,pos.y + 1 }, size, Cnt + 1);
	}
	else if (Check[2] == true || Check[3] == true)
	{
		return HitCheck({ pos.x,pos.y - 1 }, size, Cnt + 1);
	}

	return pos;
}

void MapMnager::SysInit()
{
	LoadDivGraph("image/tile.png", 9, 3, 3, 32, 32, bgImage);
	FILE* fp;
	fopen_s(&fp, "Data/tester.dat", "rb");
	if (fp != nullptr)
	{
		std::vector<int> map;
		int x, y, i = 0;
		fscanf(fp, "%d %d", &x, &y);
		map.resize(x * y);
		while (i < x * y)
		{
			fscanf(fp, "%d", &map[i]);
			i++;
		}
		fclose(fp);
		Map.resize(y);
		int z = 0;
		for (int i = 0; i < y; i++)
		{
			Map[i].resize(x);
			for (int j = 0; j < x; j++)
			{
				Map[i][j] = map[z];
				z++;
			}
		}

		MapSize = { x * 32,y * 32 };
		MapScreen = MakeScreen(MapSize.x, MapSize.y, true);
		SetDrawScreen(MapScreen);
		for (i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				DrawRotaGraph(j * 32 + 16, i * 32 + 16, 1.0, 0, bgImage[Map[i][j]], true);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
	}
	_pos = { MapSize.x / 2 - ScrCenter.x, ScrCenter.y };
}
