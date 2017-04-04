#include "stdafx.h"
#include "KillCommand.h"


KillCommand::KillCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


KillCommand::~KillCommand()
{
}

int KillCommand::execute(){
	vector<wstring> arguments = getArguments();
	if (arguments.size() > 0){
		for (vector<wstring>::iterator it = arguments.begin(); it != arguments.end(); it++){
			int processToKill = stoi(*it);
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE |
				PROCESS_VM_READ,
				FALSE, processToKill);
			if (hProcess != NULL){
				TerminateProcess(hProcess, 0);
			}
			CloseHandle(hProcess);
		}
	}
	return GetLastError();
}