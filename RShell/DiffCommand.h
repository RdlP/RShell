#pragma once
#include "Command.h"
class DiffCommand :
	public Command
{
public:
	DiffCommand(wstring, Shell*);
	~DiffCommand();
	int execute();
};

