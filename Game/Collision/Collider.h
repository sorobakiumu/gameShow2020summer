#pragma once
#include <memory>
#include <string>

class Camera;

class Character;
///<summary>
///�����蔻��\�͂������N���X
///</summary>
class Collider
{
private:
	std::string tag_;
	std::weak_ptr<Character> owner_;
    bool dead=false;
protected:
    std::shared_ptr<Camera> camera_;
public:
    bool isImmortal_ = false;
    Collider();
	Collider(std::shared_ptr<Character> owner, const char* tag,bool isImmortal);
	virtual ~Collider()=default;

    const std::string& GetTag()const;

    /// <summary> 
    /// �����傪���ɂ܂��� 
    /// </summary> 
     /// <returns>true:���Afalse:�����Ă�</returns> 
    bool OwnerIsDead()const;
    bool IsDead()const;
    /// <summary> 
    /// ������̃X�}�[�g�|�C���^��Ԃ� 
    /// </summary> 
    /// <returns>������̃X�}�[�g�|�C���^</returns> 
	std::shared_ptr<Character> GetOwner();
	virtual bool IsHit(std::shared_ptr<Collider> col)=0;
    virtual void Draw() {};
    void Suicide();
};

struct CollisionInfo
{
    std::shared_ptr <Collider> collider;
};