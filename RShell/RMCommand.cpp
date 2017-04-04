#include "stdafx.h"
#include "RMCommand.h"


RMCommand::RMCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


RMCommand::~RMCommand()
{
}

int RMCommand::execute(){
	vector<wstring> arguments = getArguments();
	if (arguments.size() > 0){
		for (vector<wstring>::iterator it = arguments.begin(); it != arguments.end(); it++){
			wstring fileToRemove = *it;
			DeleteFileW(fileToRemove.c_str());
		}
	}
	return GetLastError();
}
