#pragma once
#include<memory>
#include <deque>
#include <functional>

class Scene;
class Input;
class Applivation;
class SceneController
{
private:

	std::deque<std::shared_ptr<Scene>> scene_;
	std::function<void(void)> postDrawExecuter_;
public:
	SceneController();
	///シーンをシーンスタックの頭に入れる
	void pushScene(Scene*);

	//シーンスタックの先頭を削除する
	void PopScene();

	//シーンスタックを一度クリアしてから指定のシーンに移動する
	//切り替え先のシーンオブジェクト
	//前のシーンは呼出し語に削除されるためこの関数の呼び出し後に処理を行ってはならない
	void CleneChangeScene(Scene*);

	//シーンを切り替える
	//切り替え先のシーンオブジェクト
	//前のシーンは呼出し語に削除されるためこの関数の呼び出し後に処理を行ってはならない
	void ChengeScene(Scene*);

	//持っている戦闘シーンのアップデートを呼ぶ
	void Update(const Input&);

	//持っているシーンすべてを描画する
	void Draw();
	void ClearScene();
	void PushScene(Scene* scene);

};

