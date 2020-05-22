#pragma once
#include "Gimmick.h"
class Canon :
    public Gimmick
{
public:
    Canon();
    Canon(Vec2double pos,double rad,int speed);
    ~Canon();
    void UpDate();
    void Draw();
private:
    int Image;
    int Speed;
    double Rad;
    int Cnt;
};

