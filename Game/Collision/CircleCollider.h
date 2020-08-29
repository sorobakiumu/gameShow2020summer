#pragma once
#include "Collider.h"
#include "../../Geometry.h"
///<summry>
///�~�̓����蔻��N���X
///</summry>
class CircleCollider :
	public Collider
{
private:
    Circle circle_;///<����Ɏg���~ 
    
public:
    /// <summary> 
    /// �����Ȃ����{0,0},0 �u�~�̃R���C�_�[�v 
    /// </summary> 
    CircleCollider() :circle_({ 0,0 }, 0){}

    /// <summary> 
    /// �~��񂩂�~�Փ˔������� 
    /// </summary> 
    /// <param name="c">�~���</param> 
    CircleCollider(std::shared_ptr<Character> owner, const char* tag);

    /// <summary> 
    /// ���S�Ɣ��a����~�Փˏ������ 
    /// </summary> 
    /// <param name="p">���S</param> 
    /// <param name="r">���a</param> 
    CircleCollider(std::shared_ptr<Character> owner, const char* tag, Circle c);

    bool IsHit(std::shared_ptr<Collider> col)override;

    const Position2f ActualPosition();
    void Draw();

    const Circle& GetCircle()const;
};

