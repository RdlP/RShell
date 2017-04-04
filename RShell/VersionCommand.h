#pragma once
#include "Command.h"
class VersionCommand :
	public Command
{
public:
	VersionCommand(wstring, Shell*);
	virtual ~VersionCommand();
	int execute();
};

