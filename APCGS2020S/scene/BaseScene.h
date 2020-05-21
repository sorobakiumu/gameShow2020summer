#pragma once
#include<memory>
#include <string>

class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;
class BaseScene
{
public:
	BaseScene();
	virtual unique_Base Update(unique_Base own) = 0;	
	virtual ~BaseScene();
};
