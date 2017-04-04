#include "stdafx.h"
#include "MVCommand.h"


MVCommand::MVCommand(wstring line, Shell *shell) : Command(line, shell)
{
}


MVCommand::~MVCommand()
{
}

int MVCommand::execute(){
	wstring dst = getArguments().at(1);
	wstring src = getArguments().at(0);
	MoveFile(src.c_str(), dst.c_str());
	return GetLastError();
}