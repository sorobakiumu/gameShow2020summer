#include "Obj.h"
#include "../manager/SceneManage.h"

Obj::Obj()
{
	alive = true;
	dead = false;
	_animFlam = 0;
	_animCnt = 0;
	_zOrder = 0;
	_state = STATE::NORMAL;
	_rad = 0.0;
	ID = OBJ_ID::MAX;
	G_ID = GIMMICK_ID::NON;
}

Obj::~Obj()
{

}

// 一枚絵(ｱﾆﾒｰｼｮﾝなし)を描画する関数
void Obj::Draw(Vec2double pos, int id)
{
	lpSceneMng.addDrawQue({ pos , _rad , _zOrder, id , LAYER::MAP , 900 });
}

// ｱﾆﾒｰｼｮﾝ変更関数
bool Obj::State(const STATE state)
{
	// そもそもｱﾆﾒｰｼｮﾝが設定されてなかったらさよならバイバイ
	if (_animMap.find(state) == _animMap.end())
	{
		return false;
	}

	// ｱﾆﾒｰｼｮﾝが切り替わった時、ｱﾆﾒｰｼｮﾝ関連を初期化する
	if (_state != state)
	{
		_animFlam = 0;
		_animCnt = 0;
	}

	// ｱﾆﾒｰｼｮﾝを切り替える
	_state = state;

	return true;
}

// 現在の状態を取得する
const STATE Obj::animKey(void) const
{
	return _state;
}

// ID毎のｱﾆﾒｰｼｮﾝ番号とｱﾆﾒｰｼｮﾝﾌﾚｰﾑを譲渡
bool Obj::SetAnim(const STATE state, AnimVector& data)
{
	// animMapのAnimVectorを返す
	return (_animMap.try_emplace(state, std::move(data))).second;
}

// 死亡時ｱﾆﾒｰｼｮﾝ終了可能かどうかを識別する関数
bool Obj::isAnimEnd(void)
{
	// 安全装置1(描画予定の画像が存在しているかの確認)
	if (_animMap.find(_state) == _animMap.end())
	{
		return true;
	}

	// 安全装置2(描画予定の画像がｺﾏ数を超えていないかの確認)
	if ((_animMap[_state].size() <= _animFlam) || (_animFlam < 0))
	{
		return true;
	}

	// ｱﾆﾒｰｼｮﾝが終了した場合trueを返す
	if (_animMap[_state][_animFlam].first == -1)
	{
		return true;

	}
	else   // そうでなければfalseを返す
	{
		return false;
	}
}

// 生存ｽﾃｰﾀｽ変更用関数
bool Obj::SetAlive(bool _alive)
{
	alive = _alive;
	if (!alive)
	{
		State(STATE::DEATH);
	}

	return true;
}

// 完全に削除可能かを識別する関数
bool Obj::Destroyproc(void)
{
	// 生きてたら何もしない
	if (alive)
	{
		return false;
	}

	// 死んでて、かつｱﾆﾒｰｼｮﾝが完全終了してたら消す
	if (isAnimEnd())
	{
		dead = true;
	}

	return true;
}
