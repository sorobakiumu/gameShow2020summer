#pragma once
#include "Gimmick.h"
class Bullet :
    public Gimmick
{
public:
    Bullet();
    Bullet(Vec2double pos,int speed,double rad);
    ~Bullet();

    void UpDate();
    void Draw();
private:
    int Image;
    int Speed;
};

