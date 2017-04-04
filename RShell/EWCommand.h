#pragma once
#include "Command.h"
class EWCommand :
	public Command
{
public:
	EWCommand(wstring line, Shell* shell);
	virtual ~EWCommand();
	int execute();
private:
	static BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lparam);
};

