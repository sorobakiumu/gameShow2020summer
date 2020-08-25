#pragma once
#include <memory>
#include"../Scene/Scene.h"
#include "Input.h"


class SceneController;
struct Size;
//表示すべき画面の情報を持つ。
class Viewport {
public:
	Size& GetSize() const;
};
class Application
{
private:
	Viewport viewport;
	std::shared_ptr<SceneController> _sceneContller;

	Application() = default;
	Application(const Application&) = delete;
	void operator = (const Application&) = delete;

	Input input;
public:
	//スングルトンインスタンス
	static Application& Instance() {
		static Application instance;
		return instance;
	}
	//初期化
	bool Initalaize();
	//ラン
	void Run();
	//後処理
	void Terminate();
	///<summary>
	///アプリケーションを終了する
	///</summary>
	void Exit();

	const Viewport& GetViewport()const;
};

