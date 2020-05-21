#pragma once
#include "Gimmick.h"
class FallNeedle :
    public Gimmick
{
    FallNeedle();
    FallNeedle(Vec2double pos);
    ~FallNeedle();

    void UpDate();
    void Draw();

private:
    bool FallFlag;
    int Image;
};

