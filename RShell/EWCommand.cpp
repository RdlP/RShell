#include "stdafx.h"
#include "EWCommand.h"


EWCommand::EWCommand(wstring line, Shell *shell) : Command(line, shell)
{
}


EWCommand::~EWCommand()
{
}

BOOL IsAltTabWindow(HWND hwnd)
{
	TITLEBARINFO ti;
	HWND hwndTry, hwndWalk = NULL;

	if (!IsWindowVisible(hwnd))
		return FALSE;

	hwndTry = GetAncestor(hwnd, GA_ROOTOWNER);
	while (hwndTry != hwndWalk)
	{
		hwndWalk = hwndTry;
		hwndTry = GetLastActivePopup(hwndWalk);
		if (IsWindowVisible(hwndTry))
			break;
	}
	if (hwndWalk != hwnd)
		return FALSE;

	// the following removes some task tray programs and "Program Manager"
	ti.cbSize = sizeof(ti);
	GetTitleBarInfo(hwnd, &ti);
	if (ti.rgstate[0] & STATE_SYSTEM_INVISIBLE)
		return FALSE;

	// Tool windows should not be displayed either, these do not appear in the
	// task bar.
	if (GetWindowLong(hwnd, GWL_EXSTYLE) & WS_EX_TOOLWINDOW)
		return FALSE;

	return TRUE;
}

BOOL EWCommand::enumWindowsProc(HWND hwnd, LPARAM lParam){
	Command *pThis = reinterpret_cast<Command *>(lParam);
	wchar_t class_name[80];
	wchar_t title[500];
	if (!IsAltTabWindow(hwnd)){
		return TRUE;
	}
	GetClassName(hwnd, class_name, sizeof(class_name));
	GetWindowText(hwnd, title, sizeof(title));
	wstringstream wss;
	wss << (int)hwnd << "\t" << title << endl;
	pThis->appendResult(wss.str());
	return TRUE;
}

int EWCommand::execute(){

	if (containsParameter(L"m")){
		wstring arg = getArguments().at(0);
		HWND handle = (HWND)stoi(arg);
		
		CloseWindow(handle);
	}
	else if (containsParameter(L"d")){
		wstring arg = getArguments().at(0);
		HWND handle = (HWND)stoi(arg);

		//DestroyWindow(handle);
		SendMessage(handle, WM_CLOSE, 0, 0);
	}
	else{

		bool success = EnumWindows(enumWindowsProc, reinterpret_cast<LPARAM>(this));
	}
	return GetLastError();
}