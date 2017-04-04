#pragma once
#include "Command.h"
class EchoCommand :
	public Command
{
public:
	EchoCommand(wstring, Shell*);
	~EchoCommand();
	int execute();
};

