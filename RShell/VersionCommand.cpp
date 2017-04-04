#include "stdafx.h"
#include "VersionCommand.h"


VersionCommand::VersionCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


VersionCommand::~VersionCommand()
{
}

int VersionCommand::execute(){
	wstring version;
	version = L"rsh 0.46a - Ángel Luis";
	appendResult(version);
	return GetLastError();
}