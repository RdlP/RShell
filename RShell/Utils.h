#pragma once

#include <string>
#include <Windows.h>

using namespace std;

class Utils
{
public:
	Utils();
	~Utils();
	static bool isSourceADirectory(wstring src);
	static wstring appendFileNameToDirectory(wstring src, wstring file);
};

