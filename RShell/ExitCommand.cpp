#include "stdafx.h"
#include "ExitCommand.h"


ExitCommand::ExitCommand(wstring line, Shell *shell) : Command(line, shell)
{
}


ExitCommand::~ExitCommand()
{
}

int ExitCommand::execute(){

	ExitProcess(0);
	return GetLastError();
}