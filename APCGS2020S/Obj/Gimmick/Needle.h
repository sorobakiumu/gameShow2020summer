#pragma once
#include "Gimmick.h"

class Needle :
    public Gimmick
{
    Needle();
    Needle(Vec2double pos);
    ~Needle();

    void UpDate();
    void Draw();
private:
    int Image;
};

