#include "stdafx.h"
#include "CPCommand.h"


CPCommand::CPCommand(wstring line, Shell *shell) : Command(line, shell)
{
}


CPCommand::~CPCommand()
{
}

int CPCommand::execute(){
	wstring dst = getArguments().at((getArguments().size() - 1));
	wstringstream stream;
	for (int i = 0; i < getArguments().size() - 1; i++){
		wstring src = getArguments().at(i);
		if (Utils::isSourceADirectory(src)){
			stream << src << " no es un archivo" << endl;
			continue;
		}
		if (Utils::isSourceADirectory(dst)){
			dst = Utils::appendFileNameToDirectory(dst, src);
		}
		bool valid = CopyFileW(src.c_str(), dst.c_str(), FALSE);
		int error = GetLastError();
	}
	return GetLastError();
	
}



