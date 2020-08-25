#include "SceneController.h"
#include "TitleSccene.h"
#include <assert.h>
#include <DxLib.h>

SceneController::SceneController() 
{
	scene_.emplace_front(new TitleScene(*this));
	postDrawExecuter_ = []() {};
}

void SceneController::pushScene(Scene* scene)
{
	postDrawExecuter_ = [this, scene]() {scene_.emplace_front(scene); };
}

void SceneController::PopScene()
{
	postDrawExecuter_ = [this]() {scene_.erase(scene_.begin());assert(!scene_.empty()); };

}

void SceneController::ChengeScene(Scene* scene)
{
	
	postDrawExecuter_ = [this, scene]() {scene_.pop_front();scene_.emplace_front(scene); };
}

void SceneController::Update(const Input& input)
{
	assert(!scene_.empty());
	scene_.front()->Update(input);

}
void SceneController::Draw()
{
	auto rit = scene_.rbegin();
	for (; rit != scene_.rend(); ++rit) {
		if (!scene_.empty()) {
			(*rit)->Draw();
		}
	}

	postDrawExecuter_(); 
	postDrawExecuter_ = []() {};
}

void SceneController::ClearScene()
{
	scene_.clear();
}

void SceneController::CleneChangeScene(Scene* scene)
{
	postDrawExecuter_ = [this, scene]() {scene_.clear();scene_.emplace_front(scene); };
}

void SceneController::PushScene(Scene* scene)
{
	scene_.emplace_front(scene);
}