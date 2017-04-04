#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Shell.h"
#include <sstream>
#include "Utils.h"
#include <fstream>

using namespace std;

class Command
{
public:
	Command(wstring, Shell*);
	virtual ~Command();
	virtual int execute() = 0;
	vector<wstring> getParameters();
	vector<wstring> getArguments();
	Shell* getShell();
	wstring getResult();
	void appendResult(wstring);
	bool containsArgument(wstring argument);
	bool containsParameter(wstring parameter);
	bool hasOutputRedirection();
	void doOutputRedirection();
	wstring getCommand();
	wstring getCommandline();

private:
	void parse(wstring);
	wstring command;
	wstring commandline;
	wstring argumentsAndParameters;
	vector<wstring> parameters;
	vector<wstring> arguments;
	Shell* mShell;
	wstringstream result;
};

