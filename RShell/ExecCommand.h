#pragma once
#include "Command.h"
class ExecCommand :
	public Command
{
public:
	ExecCommand(wstring, Shell*);
	virtual ~ExecCommand();
	int execute();
};

