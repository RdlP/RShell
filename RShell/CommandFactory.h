#pragma once

#include "Command.h"
#include <string>
#include "CDCommand.h"
#include "PWDCommand.h"
#include "LSCommand.h"
#include "CPCommand.h"
#include "MVCommand.h"
#include "RMDirCommand.h"
#include "MkDirCommand.h"
#include "TouchCommand.h"
#include "RMCommand.h"
#include "CatCommand.h"
#include "EchoCommand.h"
#include "EWCommand.h"
#include "ExitCommand.h"
#include "UNameCommand.h"
#include "WhoAmICommand.h"
#include "PSCommand.h"
#include "KillCommand.h"
#include "ExecCommand.h"
#include "TailCommand.h"
#include "HeadCommand.h"
#include "VersionCommand.h"
#include "DiffCommand.h"

class CommandFactory
{
public:
	CommandFactory();
	virtual ~CommandFactory();
	static Command* createCommand(wstring, Shell*);
};

