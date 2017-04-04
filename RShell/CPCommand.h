#pragma once
#include "Command.h"
class CPCommand :
	public Command
{
public:
	CPCommand(wstring line, Shell* shell);
	virtual ~CPCommand();
	int execute();
};

