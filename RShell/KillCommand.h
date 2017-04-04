#pragma once
#include "Command.h"
class KillCommand :
	public Command
{
public:
	KillCommand(wstring, Shell*);
	virtual ~KillCommand();
	int execute();
};

