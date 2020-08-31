#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Geometry.h"
#include "../Scene/GamePlaingScene.h"
#include <DxLib.h>

struct StageHeader
{
	char id[4];
	unsigned int size;
	unsigned int mapW;
	unsigned int mapH;
	unsigned char chipW;
	unsigned char chipH;
	unsigned char layer;
	unsigned char bitcnt;
};

class Camera;

class Stage
{
private:

	std::vector<Segment> terrainSegment_;

	std::shared_ptr<Camera> camera_;
	using StageLayerData_t = std::vector<unsigned char>;
	std::vector<StageLayerData_t> stagedata_;
	StageHeader stageHeader_ = {};
	void CreateSegment(Position2f& lastPos, Position2f& pos);
	bool isBossMode_=false;
	using Update_t = void (Stage::*)();
	Update_t updater_;
	GamePlaingScene* gamescene_;
	void NormalUpdate();
	void BossUpdate();
	void BildEnemyLayout();
public:
	std::array<Segment, 3> GetThreeSegment(const Position2f& pos)const;
	void Load(const TCHAR* path,std::shared_ptr<Camera> camera);
	float ComputeGlandY(const Position2f& pos)const;
	Vector2f ComputeOverlapWall(const Position2f& pos,float f)const;

	void CheckBossMode();

	//ÉXÉNÉçÅ[ÉãÇÃí‚é~
	bool IsBossMode()const;

	void Update();
	void Draw();
	Stage(std::shared_ptr<Camera> camera, GamePlaingScene* gs);
};

