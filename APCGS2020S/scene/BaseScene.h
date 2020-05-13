#pragma once
#include<memory>
class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;
class BaseScene
{
public:
	BaseScene();
<<<<<<< HEAD
	virtual unique_Base Update(unique_Base own) = 0;	
	virtual ~BaseScene();
};
=======
	virtual unique_Base Update(unique_Base own) = 0;	//シーンを、更新する。
	virtual ~BaseScene();
};

>>>>>>> 5ffb7be724dad423b8821f9521aeeb4f27d2817f
