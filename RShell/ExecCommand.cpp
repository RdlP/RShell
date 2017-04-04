#include "stdafx.h"
#include "ExecCommand.h"


ExecCommand::ExecCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


ExecCommand::~ExecCommand()
{
}

int ExecCommand::execute(){
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));
	wstring ws = getCommandline();
	CreateProcess(NULL, &ws[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

	if (!containsArgument(L"&")){
		WaitForSingleObject(pi.hProcess, INFINITE);
	}
	else{
		wstringstream result;
		result << L"pid: " << pi.hProcess << endl;
		appendResult(result.str());
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return GetLastError();
}
