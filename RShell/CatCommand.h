#pragma once
#include "Command.h"
#include <fstream>
class CatCommand :
	public Command
{
public:
	CatCommand(wstring, Shell*);
	~CatCommand();
	int execute();
};

