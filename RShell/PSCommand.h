#pragma once
#include "Command.h"
#include <Psapi.h>
class PSCommand :
	public Command
{
public:
	PSCommand(wstring, Shell*);
	~PSCommand();
	int execute();

private:
	wstring getProcessName(DWORD);
	wstring getProcessPath(DWORD);
	wstring getAdvanceProcessInfo(DWORD);
};

