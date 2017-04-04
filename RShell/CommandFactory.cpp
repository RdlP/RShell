#include "stdafx.h"
#include "CommandFactory.h"


CommandFactory::CommandFactory()
{
}


CommandFactory::~CommandFactory()
{
}

Command* CommandFactory::createCommand(wstring input, Shell* shell){
	Command *command;
	wistringstream iss(input);
	wstring c;
	iss >> c;
	if (c == L"cd"){
		command = new CDCommand(input, shell);
	}
	else if (c == L"ls"){
		command = new LSCommand(input, shell);
	}
	else if (c == L"cp"){
		command = new CPCommand(input, shell);
	}
	else if (c == L"mv"){
		command = new MVCommand(input, shell);
	}
	else if (c == L"rm"){
		command = new RMCommand(input, shell);
	}
	else if (c == L"mkdir"){
		command = new MkDirCommand(input, shell);
	}
	else if (c == L"rmdir"){
		command = new RMDirCommand(input, shell);
	}
	else if (c == L"touch"){
		command = new TouchCommand(input, shell);
	}
	else if (c == L"cat"){
		command = new CatCommand(input, shell);
	}
	else if (c == L"echo"){
		command = new EchoCommand(input, shell);
	}
	else if (c == L"ew"){
		command = new EWCommand(input, shell);
	}
	else if (c == L"whoami"){
		command = new WhoAmICommand(input, shell);
	}
	else if (c == L"uname"){
		command = new UNameCommand(input, shell);
	}
	else if (c == L"ps"){
		command = new PSCommand(input, shell);
	}
	else if (c == L"exit"){
		command = new ExitCommand(input, shell);
	}
	else if (c == L"kill"){
		command = new KillCommand(input, shell);
	}
	else if (c == L"pwd"){
		command = new PWDCommand(input, shell);
	}
	else if (c == L"tail"){
		command = new TailCommand(input, shell);
	}
	else if (c == L"head"){
		command = new HeadCommand(input, shell);
	}
	else if (c == L"version"){
		command = new VersionCommand(input, shell);
	}
	else if (c == L"diff"){
		command = new DiffCommand(input, shell);
	}
	else{
		command = new ExecCommand(input, shell);
	}

	return command;
}