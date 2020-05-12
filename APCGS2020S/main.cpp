#include <stdio.h>
#include <Windows.h>
#include "Scene/SceneManage.h"

int main()
{
	SceneManage::GetInstance().Run();
	SceneManage::Destroy();
	SceneManage::GetInstance().Run();

	return 0;
}