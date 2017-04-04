#pragma once
#include "Command.h"
class TouchCommand :
	public Command
{
public:
	TouchCommand(wstring, Shell*);
	~TouchCommand();
	int execute();
};

