#include "stdafx.h"
#include "HeadCommand.h"


HeadCommand::HeadCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


HeadCommand::~HeadCommand()
{
}

int HeadCommand::execute(){
	if (getArguments().size() > 0){
		wstring file = getArguments().at(0);
		wifstream infile(file);
		int numberOfLinesToBeRead = 10;
		if (getParameters().size() > 0){
			numberOfLinesToBeRead = stoi(getParameters().at(0));
		}
		int i = 0;
		wstringstream stream;
		while (infile.good() && i < numberOfLinesToBeRead){
			i++;
			wstring sLine;
			getline(infile, sLine);
			
			stream << sLine << endl;
		}
		appendResult(stream.str());
		infile.close();
	}
	return GetLastError();
	
}