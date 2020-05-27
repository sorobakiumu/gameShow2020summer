#pragma once
#include "Gimmick.h"
class Generator :
    public Gimmick
{
public:
    Generator();
    Generator(Vec2double pos,int speed);
    ~Generator();

    void UpDate();
    void Draw();
private:
    int Image;
    int FCnt;           // フレームカウント 
    int GCnt;           // 生産数のカウント
    int Speed;          // 敵生産の間隔
}; 

