#include "stdafx.h"
#include "RMDirCommand.h"


RMDirCommand::RMDirCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


RMDirCommand::~RMDirCommand()
{
}

int RMDirCommand::execute(){
	vector<wstring> arguments = getArguments();
	if (getArguments().size() > 0){
		for (vector<wstring>::iterator it = arguments.begin(); it != arguments.end(); it++){
			wstring folderToRemove = *it;
			RemoveDirectoryW(folderToRemove.c_str());
		}
	}
	return GetLastError();
}
