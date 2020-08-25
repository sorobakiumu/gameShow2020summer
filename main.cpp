#include <Windows.h>
#include "System/Application.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE , LPSTR ,int ) 
{
	auto& app = Application::Instance();
	if (!app.Initalaize()){

	}
	app.Run();
	app.Terminate();


}


