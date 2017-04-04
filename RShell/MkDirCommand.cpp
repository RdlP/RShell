#include "stdafx.h"
#include "MkDirCommand.h"


MkDirCommand::MkDirCommand(wstring line, Shell* shell) : Command(line,shell)
{
}


MkDirCommand::~MkDirCommand()
{
}

int MkDirCommand::execute(){
	vector<wstring> arguments = getArguments();
	if (arguments.size() > 0){
		for (vector<wstring>::iterator it = arguments.begin(); it != arguments.end(); it++){
			wstring folderToCreate = *it;
			CreateDirectoryW(folderToCreate.c_str(), NULL);
		}
	}
	return GetLastError();
}
