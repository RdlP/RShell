#include "stdafx.h"
#include "UNameCommand.h"


UNameCommand::UNameCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


UNameCommand::~UNameCommand()
{
}

int UNameCommand::execute(){
	wstringstream stream;
	SYSTEM_INFO sys;
	LPSYSTEM_INFO systemInfo = &sys;
	OSVERSIONINFO win;
	LPOSVERSIONINFO windowsInfo = &win;

	/* GetVersionEx es obsoleta
	GetVersionEx(windowsInfo);
	if (windowsInfo->dwMajorVersion == 10 && windowsInfo->dwMinorVersion == 0){
		stream << "Windows 10";
	}
	else if (windowsInfo->dwMajorVersion == 6 && windowsInfo->dwMinorVersion == 3){
		stream << "Windows 8.1";
	}
	else if (windowsInfo->dwMajorVersion == 6 && windowsInfo->dwMinorVersion == 2){
		stream << "Windows 8";
	}
	else if (windowsInfo->dwMajorVersion == 6 && windowsInfo->dwMinorVersion == 1){
		stream << "Windows 7";
	}
	else if (windowsInfo->dwMajorVersion == 6 && windowsInfo->dwMinorVersion == 0){
		stream << "Windows Vista";
	}
	else if (windowsInfo->dwMajorVersion == 5 && windowsInfo->dwMinorVersion == 1){
		stream << "Windows XP";
	}
	else if (windowsInfo->dwMajorVersion == 5 && windowsInfo->dwMinorVersion == 0){
		stream << "Windows 2000";
	}

	stream << " " << windowsInfo->szCSDVersion;*/

	GetSystemInfo(systemInfo);
	if (systemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64){
		stream << L" x64 (AMD or Intel)";
	}
	else if (systemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM){
		stream << L" ARM";
	}
	else if (systemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64){
		stream << L" Intel Itanium-based";
	}
	else if (systemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL){
		stream << L" x86";
	}
	else if (systemInfo->wProcessorArchitecture == PROCESSOR_ARCHITECTURE_UNKNOWN){
		stream << L" Unknown architecture.";
	}

	stream << " Tamaño de página " << systemInfo->dwPageSize;
	stream << " Número de procesadores " << systemInfo->dwNumberOfProcessors;

	appendResult(stream.str());
	return GetLastError();
}
