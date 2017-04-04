#pragma once
#include "Command.h"
#include <Lmcons.h>
class WhoAmICommand :
	public Command
{
public:
	WhoAmICommand(wstring, Shell*);
	~WhoAmICommand();
	int execute();
};

