#include "stdafx.h"
#include "LSCommand.h"


LSCommand::LSCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


LSCommand::~LSCommand()
{
}

int LSCommand::execute(){
	HANDLE hFind;
	WIN32_FIND_DATA data;
	wstring path;
	if (getArguments().size() == 0){
		TCHAR buffer[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, buffer);
		std::wstring arr_w(buffer);
		path = buffer;
		path += L"\\*";
	}
	else{
		path = getArguments().at(0);
		path += L"\\*";
	}
	hFind = FindFirstFile(path.c_str(), &data);
	wstringstream r;
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (containsParameter(L"l")){
				int size = ((data.nFileSizeHigh << 8) | (data.nFileSizeLow));
				r << makeAttributes(data.dwFileAttributes) << " " << size << "\t" << makeDateTime(&data.ftCreationTime) << "\t" << data.cFileName << endl;
			}
			else{
				r << data.cFileName << "\t";
			}
			//appendResult(r);
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}
	appendResult(r.str());
	return GetLastError();
}

wstring LSCommand::makeDateTime(FILETIME *ft){
	SYSTEMTIME s;
	LPSYSTEMTIME st = &s;
	FileTimeToSystemTime(ft, st);
	wstringstream stream;
	
	wchar_t buffer[100];
	swprintf(buffer, 100, L"%02d-%02d-%d %02d:%02d", st->wDay, st->wMonth, st->wYear, st->wHour, st->wMinute);
	wstring result(buffer);
	stream << result;
	return stream.str();
}

wstring LSCommand::makeAttributes(int attr){
	wstringstream stream;
	if (attr & FILE_ATTRIBUTE_DIRECTORY){
		stream << "d";
	}
	else{
		stream << "-";
	}

	if (attr & FILE_ATTRIBUTE_HIDDEN){
		stream << "h";
	}
	else{
		stream << "-";
	}

	if (attr & FILE_ATTRIBUTE_SYSTEM){
		stream << "s";
	}
	else{
		stream << "-";
	}

	if (attr & FILE_ATTRIBUTE_COMPRESSED){
		stream << "c";
	}
	else{
		stream << "-";
	}

	if (attr & FILE_ATTRIBUTE_ENCRYPTED){
		stream << "e";
	}
	else{
		stream << "-";
	}

	if (attr & FILE_ATTRIBUTE_READONLY){
		stream << "r";
	}
	else{
		stream << "-";
	}

	return stream.str();
}
