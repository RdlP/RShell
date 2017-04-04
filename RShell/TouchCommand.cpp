#include "stdafx.h"
#include "TouchCommand.h"


TouchCommand::TouchCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


TouchCommand::~TouchCommand()
{
}

int TouchCommand::execute(){
	if (getArguments().size() > 0){
		wstring fileToCreate = getArguments().at(0);
		HANDLE hwnd = CreateFileW(fileToCreate.c_str(), GENERIC_READ, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hwnd != INVALID_HANDLE_VALUE){
			CloseHandle(hwnd);
		}
	}
	return GetLastError();
}