#include "stdafx.h"
#include "Shell.h"
#include "Command.h"
#include <sstream>
#include "CommandFactory.h"
#include <Lmcons.h>


Shell::Shell(){

}

Shell::~Shell(){

}

wstring Shell::getCurrentDirectory(){

	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, buffer);
	std::wstring arr_w(buffer);

	return arr_w;
}

wstring Shell::getCurrentUser(){
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	std::wstring arr_w(username);

	return arr_w;
}

void Shell::setCurrentDirectory(wstring newDirectory){
	currentDirectory = newDirectory;
}

void Shell::showPrompt(){
	wcout << getCurrentUser() << L"@" << getCurrentDirectory() << L"]$ ";
}

void Shell::run(){
	while (1){
		showPrompt();
		wstring input;
		getline(wcin, input);
		wcin.ignore();

		Command *command = CommandFactory::createCommand(input, this);
		command->execute();
		if (command->hasOutputRedirection()){
			command->doOutputRedirection();
		}
		else{
			wstring result = command->getResult();
			if (result.length() > 0){
				wcout << result << endl;
			}
		}
		delete command;
	}
}