#include "stdafx.h"
#include "PSCommand.h"


PSCommand::PSCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


PSCommand::~PSCommand()
{
}

wstring PSCommand::getProcessName(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name.

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
			&cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName,
				sizeof(szProcessName) / sizeof(TCHAR));
		}
	}
	wstringstream stream;

	stream << szProcessName;

	CloseHandle(hProcess);

	return stream.str();
}

wstring PSCommand::getProcessPath(DWORD processID)
{
	TCHAR szProcessPath[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name.

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
			&cbNeeded))
		{
			GetModuleFileNameEx(hProcess, hMod, szProcessPath, sizeof(szProcessPath) / sizeof(TCHAR));
		}
	}

	wstringstream stream;

	stream<< szProcessPath;

	CloseHandle(hProcess);

	return stream.str();
}

wstring PSCommand::getAdvanceProcessInfo(DWORD processID)
{
	MODULEINFO mInfo;

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);


	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
			&cbNeeded))
		{
			GetModuleInformation(hProcess, hMod, &mInfo, sizeof(mInfo));
		}
	}

	wstringstream stream;

	stream << "Dirección base: " << mInfo.lpBaseOfDll << endl << "Tamaño: " << mInfo.SizeOfImage << " bytes" <<endl<<"Punto de entrada: " << mInfo.EntryPoint;

	CloseHandle(hProcess);

	return stream.str();
}

int PSCommand::execute(){
	wstringstream stream;
	if (getArguments().size() == 0){
		DWORD aProcesses[1024], cbNeeded, cProcesses;
		unsigned int i;
		if (EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		{
			cProcesses = cbNeeded / sizeof(DWORD);

			for (i = 0; i < cProcesses; i++)
			{
				if (aProcesses[i] != 0)
				{
					//getProcessNameAndID(aProcesses[i]);
					stream << aProcesses[i] << "\t\t" << getProcessName(aProcesses[i]) << endl;
				}
			}
		}
	}
	else{
		DWORD pid = stoi(getArguments().at(0));
		stream << "Ruta: " << getProcessPath(pid) << endl;
		stream << getAdvanceProcessInfo(pid);
	}
	appendResult(stream.str());
	return GetLastError();
}
