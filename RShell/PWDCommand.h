#pragma once
#include "Command.h"
class PWDCommand :
	public Command
{
public:
	PWDCommand(wstring line, Shell* shell);
	virtual ~PWDCommand();
	int execute();
};

