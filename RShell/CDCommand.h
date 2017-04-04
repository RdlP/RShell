#pragma once

#include "Command.h"

class CDCommand : public Command 
{
public:
	CDCommand(wstring line, Shell*);
	virtual ~CDCommand();
	int execute();
};

