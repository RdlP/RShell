#pragma once
#include "Command.h"
class UNameCommand :
	public Command
{
public:
	UNameCommand(wstring, Shell*);
	virtual ~UNameCommand();
	int execute();
};

