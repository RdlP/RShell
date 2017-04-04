#pragma once

#include <string>
#include <iostream>

using namespace std;

class Shell
{
public:
	Shell();
	virtual ~Shell();
	void run();
	wstring getCurrentDirectory();
	wstring getCurrentUser();
	void setCurrentDirectory(wstring);
	void showPrompt();

private:
	wstring currentDirectory;

};

