#include "Scene.h"
#include "DxLib.h"
#include<algorithm>

using namespace std;

//void Input::UpDate()
//{
//	std::copy(begin(keyState), end(keyState), begin(lastkeyState), end(lastkeyState));
//	GetHitKeyStateAll(keyState);
//}

Scene::Scene(SceneController& c):controller_(c)
{

}
