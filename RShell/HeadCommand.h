#pragma once
#include "Command.h"
class HeadCommand :
	public Command
{
public:
	HeadCommand(wstring, Shell*);
	virtual ~HeadCommand();
	int execute();
};

