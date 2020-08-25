#pragma once
#include <vector>

class Background
{
private:
	std::vector<int> bgH_;
	int frmCnt_;
public:
	Background();
	~Background();
	void Update();
	void Draw();
};

