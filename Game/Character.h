#pragma once
#include<memory>
#include "../Geometry.h"
class Input;
struct  CollisionInfo;
class Camera;
class Character
{
protected:
	std::shared_ptr<Camera> camera_;
	Vector2f pos_;
public:
	Character(std::shared_ptr<Camera> camera);

	///<summary>キャラクターの更新を行う</summary>
	///<param name="input">入力</param>
	///<memo>プレイヤー以外に要はないパラメーターだけど必要ない奴は無視すればいい</memo>
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual ~Character()=default;
	///<summary>衝突判定イベント</summary>
	///<param name="me">入力</param>
	///<param name="another">入力</param>
	virtual void OnHit(CollisionInfo& another,CollisionInfo& me)=0;
	Position2f Pos();
	Position2f GetPosition();
	Position2 Size() { return { 32,32 }; }
	std::shared_ptr<Camera> GetCamera();
};

