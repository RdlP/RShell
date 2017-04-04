#include "stdafx.h"
#include "PWDCommand.h"


PWDCommand::PWDCommand(wstring line, Shell* shell) : Command(line,shell)
{
}


PWDCommand::~PWDCommand()
{
}

int PWDCommand::execute(){
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, buffer);
	std::wstring arr_w(buffer);
	appendResult(arr_w);
	return GetLastError();
}
