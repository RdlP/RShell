#include "stdafx.h"
#include "Utils.h"


Utils::Utils()
{
}


Utils::~Utils()
{
}

bool Utils::isSourceADirectory(wstring src){
	int attr = GetFileAttributes(src.c_str());
	return attr & FILE_ATTRIBUTE_DIRECTORY;
}

wstring Utils::appendFileNameToDirectory(wstring src, wstring file){
	wchar_t filename[MAX_PATH], extension[MAX_PATH];
	_wsplitpath_s(file.c_str(), NULL, 0, NULL, 0, filename, MAX_PATH, extension, MAX_PATH);
	wstring strFilename(filename), strExtension(extension);
	src += strFilename + strExtension;
	return src;
}