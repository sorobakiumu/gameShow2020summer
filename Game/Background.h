#pragma once
#include <vector>
#include <memory>
#include "../Geometry.h"
#include "Player/Camera.h"


struct SCREEN{
	int screen = {};
	Position2f pos_ = {};
};
class Camera;
class Background
{
private:
	std::vector<int> bgH_;
	int frmCnt_;
	SCREEN screen[11];
	SCREEN screenNext[11];
	std::shared_ptr<Camera>& camera_;
	float cameraPos_x=0.0;
	float oldCameraPos_x=0.0;
public:
	Background(std::shared_ptr<Camera>& camera);
	~Background();
	void Update();
	void Draw();
};

