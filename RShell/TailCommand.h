#pragma once
#include "Command.h"
class TailCommand :
	public Command
{
public:
	TailCommand(wstring, Shell*);
	virtual ~TailCommand();
	int execute();
};

