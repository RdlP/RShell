#include "stdafx.h"
#include "TailCommand.h"


TailCommand::TailCommand(wstring line, Shell* shell) : Command(line, shell)
{
}


TailCommand::~TailCommand()
{
}

int TailCommand::execute(){
	if (getArguments().size() > 0){
		wstring file = getArguments().at(0);
		wifstream infile(file);

		int numberOfLinesToBeRead = 10;
		if (getParameters().size() > 0){
			numberOfLinesToBeRead = stoi(getParameters().at(0));
		}
		
		int i = 0;
		wstringstream stream;	

		vector<std::wstring> lines;
		wstring line;
		while (getline(infile, line))
		{
			lines.push_back(line);
		}

		vector<wstring> lastLines;
		for (int i = lines.size() - numberOfLinesToBeRead; i < lines.size() ; i++){
			stream << lines.at(i) << endl;
		}

		appendResult(stream.str());
		infile.close();
	}
	return GetLastError();
}
