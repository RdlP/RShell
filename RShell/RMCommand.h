#pragma once
#include "Command.h"
class RMCommand :
	public Command
{
public:
	RMCommand(wstring, Shell*);
	~RMCommand();
	int execute();
};

