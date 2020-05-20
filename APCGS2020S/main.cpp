#include <stdio.h>
#include <Windows.h>
#include "manager/SceneManage.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int main()
{
	SceneManage::GetInstance().Run();
	SceneManage::Destroy();
	SceneManage::GetInstance().Run();

	return 0;
}