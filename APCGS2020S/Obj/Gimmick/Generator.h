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
    int FCnt;           // �t���[���J�E���g 
    int GCnt;           // ���Y���̃J�E���g
    int Speed;          // �G���Y�̊Ԋu
}; 

