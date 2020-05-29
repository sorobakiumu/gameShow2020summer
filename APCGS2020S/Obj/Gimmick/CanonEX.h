#pragma once
#include "Gimmick.h"
class CanonEX :
    public Gimmick
{
public:
    CanonEX();
    CanonEX(Vec2double pos, double rad, int speed);
    ~CanonEX();
    void UpDate();
    void Draw();
private:
    int Image;
    int Speed;
    int Cnt;
};
