#pragma once
#include "Command.h"
class LSCommand :
	public Command
{
public:
	LSCommand(wstring line, Shell* shell);
	~LSCommand();
	int execute();
private:
	wstring makeDateTime(FILETIME *ft);
	wstring makeAttributes(int attr);
};

