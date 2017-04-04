#include "stdafx.h"
#include "EchoCommand.h"


EchoCommand::EchoCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


EchoCommand::~EchoCommand()
{
}

int EchoCommand::execute(){
	if (getArguments().size() > 0){
		wstring toEcho = getArguments().at(0);
		if (toEcho.at(0) == '$'){
			wstring variable(toEcho, 1, toEcho.length());
			wchar_t buffer[2000];
			memset(buffer, 0, sizeof(buffer));
			GetEnvironmentVariable(variable.c_str(), buffer, sizeof(buffer));
			wstring result(buffer);
			if (!containsParameter(L"n")){
				result += L"\n";
			}
			appendResult(result);
		}
		else{
			if (!containsParameter(L"n")){
				toEcho += L"\n";
			}
			appendResult(toEcho);
		}
	}
	return GetLastError();
}
