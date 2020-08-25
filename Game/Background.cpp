#include "Background.h"
#include "DxLib.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

Background::Background()
{
	bgH_.resize(11);
	int skipno[2] = { 4,7 };
	int no = 9;
	for (unsigned int i = 0; i < bgH_.size(); ++i) {
		wstringstream wss;
		wss << L"image/BG/Layer_";
		wss << setw(4) << setfill(L'0') << i << "_";
		if (count(begin(skipno), end(skipno), i) > 0) {
			wss << "Lights";
		}
		else {
			wss << no;
			--no;
		}
		wss << ".png";
		bgH_[bgH_.size() - 1 - i] = LoadGraph(wss.str().c_str());
	}
	frmCnt_ = 0;
}

Background::~Background()
{
	for (auto& bg : bgH_) {
	DeleteGraph(bg);
	}
}

void Background::Update()
{
	frmCnt_++;

}

void Background::Draw()
{
	for (unsigned int i = 0; i < bgH_.size(); i++)
	{
		DrawExtendGraph(0, 0, 800, 600, bgH_[i], true);
	}
}

