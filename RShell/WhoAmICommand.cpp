#include "stdafx.h"
#include "WhoAmICommand.h"


WhoAmICommand::WhoAmICommand(wstring line, Shell* shell) : Command(line, shell)
{
}


WhoAmICommand::~WhoAmICommand()
{
}

int WhoAmICommand::execute(){
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	std::wstring arr_w(username);

	appendResult(arr_w);
	return GetLastError();
}
