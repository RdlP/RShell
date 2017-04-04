#pragma once
#include "Command.h"
class RMDirCommand :
	public Command
{
public:
	RMDirCommand(wstring, Shell*);
	~RMDirCommand();
	int execute();
};

