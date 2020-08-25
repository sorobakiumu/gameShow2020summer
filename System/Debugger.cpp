#include "Debugger.h"
#include <DxLib.h>

Debugger& Debugger::Instance()
{
	static Debugger instance;
	return instance;
}

bool Debugger::IsDebugMode() const
{
	return DebugDisp_;
}

void Debugger::Update()
{
#ifdef _DEBUG
	if (CheckHitKey(KEY_INPUT_F1))
	{
		DebugDisp_ = !DebugDisp_;
	}

#endif // _DEBUG
}

void Debugger::DisplayPerformance()
{
#ifdef _DEBUG
	if (DebugDisp_)
	{
		DrawFormatString(0, 0, 0xffffff, L"FPS=%f", GetFPS());
		DrawFormatString(0, 20, 0xffffff, L"DCCount=%d", GetDrawCallCount());
	}
#endif // _DEBUG
}
