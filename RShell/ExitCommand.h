#pragma once
#include "Command.h"
class ExitCommand :
	public Command
{
public:
	ExitCommand(wstring line, Shell* shell);
	virtual ~ExitCommand();
	int execute();
};

