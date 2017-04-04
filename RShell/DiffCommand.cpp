#include "stdafx.h"
#include "DiffCommand.h"


DiffCommand::DiffCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


DiffCommand::~DiffCommand()
{
}

int DiffCommand::execute(){
	return GetLastError();
}
