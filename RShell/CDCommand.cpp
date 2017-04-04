#include "stdafx.h"
#include "CDCommand.h"


CDCommand::CDCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


CDCommand::~CDCommand()
{
}

int CDCommand::execute(){
	wstring toDirectory = getArguments().at(0);
	std::wstring stemp = std::wstring(toDirectory.begin(), toDirectory.end());
	LPCWSTR sw = stemp.c_str();
	if (!SetCurrentDirectory(sw))
	{
		wstringstream stream;
		stream << "cd failed " << GetLastError() << endl;
		appendResult(stream.str());
		return GetLastError();
	}
	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, buffer);
	std::wstring arr_w(buffer);
	getShell()->setCurrentDirectory(arr_w);
	return GetLastError();
}

