#include "stdafx.h"
#include "CatCommand.h"


CatCommand::CatCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


CatCommand::~CatCommand()
{
}

int CatCommand::execute(){
	vector<wstring> arguments = getArguments();
	if (arguments.size() > 0){
		for (vector<wstring>::iterator it = arguments.begin(); it != arguments.end(); it++){
			wstring fileToRead = *it;
			ifstream in(fileToRead);
			wstring result((istreambuf_iterator<char>(in)),
				istreambuf_iterator<char>());
			appendResult(result);
		}
		
	}
	return GetLastError();
}
