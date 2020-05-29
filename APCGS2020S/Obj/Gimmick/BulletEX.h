#pragma once
#include "Gimmick.h"
class BulletEX :
    public Gimmick
{
public:

    BulletEX();
    BulletEX(Vec2double pos,int speed, double rad);
    ~BulletEX();

    void UpDate();
    void Draw();
private:
    int Image;
    int Speed;
};

