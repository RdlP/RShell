#pragma once
#include "Command.h"
class MkDirCommand :
	public Command
{
public:
	MkDirCommand(wstring, Shell*);
	~MkDirCommand();
	int execute();
};

