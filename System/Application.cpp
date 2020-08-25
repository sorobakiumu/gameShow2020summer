#include "Application.h"
#include <DxLib.h>
#include "../Scene/SceneController.h"
#include "../Scene/TitleSccene.h"
#include "../Scene/Scene.h"
#include "Input.h"
#include "../Geometry.h"
#include "Debugger.h"


namespace {
	bool isExit;
}



bool Application::Initalaize()
{
	DxLib::ChangeWindowMode(true);
	DxLib::SetGraphMode(800,600,0,0);
	if (DxLib_Init()) {
		return false;
	}
	ClsDrawScreen();
	_sceneContller = std::make_unique <SceneController>();

	bool isExit=false;
	return false;
}

void Application::Run()
{
	while (ProcessMessage() == 0)
	{

		input.Update();
		(*_sceneContller).Update(input);
		Debugger::Instance().Update();
		ClearDrawScreen();
		(*_sceneContller).Draw();
		Debugger::Instance().DisplayPerformance();
		ScreenFlip();
		if (isExit)
			break;

	}
	(*_sceneContller).ClearScene();
}

void Application::Terminate()
{
	DxLib_End();
}

void Application::Exit()
{
	isExit = true;
}

const Viewport& Application::GetViewport() const
{
	return viewport;
}

Size& Viewport::GetSize() const
{
	Size ret;
	ret.w = 800;
	ret.h = 600;
	return ret;
}
