#pragma once
#include "Gimmick.h"
class BulletEX :
    public Gimmick
{
public:

    BulletEX();
    BulletEX(Vec2double pos, double rad,int speed);
    ~BulletEX();

    void UpData();
    void Draw();
private:
    int Image;
    int Speed;
};

