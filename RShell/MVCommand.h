#pragma once
#include "Command.h"
class MVCommand :
	public Command
{
public:
	MVCommand(wstring line, Shell* shell);
	virtual ~MVCommand();
	int execute();
};

