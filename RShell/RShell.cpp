// RShell.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Shell.h"
#include <fcntl.h>
#include <io.h>
#include <Windows.h>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	setlocale(LC_ALL, "");

	/*std::wstring name;
	std::wcout << L"Enter your name: ";
	std::wcin >> name;
	std::wcout << L"Hello, " << name << std::endl;
	system("pause");*/

	Shell shell;// = new Shell();
	shell.run();
	/*while (1){

	}*/
	return 0;
}

