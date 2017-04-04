#include "stdafx.h"
#include "Command.h"


Command::Command(wstring line, Shell* shell){
	mShell = shell;
	commandline = line;
	parse(line);
}

Command::~Command(){

}

bool Command::containsArgument(wstring argument){
	if (find(arguments.begin(), arguments.end(), argument) != arguments.end()) {
		return true;
	}
	else {
		return false;
	}
}

bool Command::containsParameter(wstring parameter){
	if (find(parameters.begin(), parameters.end(), parameter) != parameters.end()) {
		return true;
	}
	else {
		return false;
	}
}

Shell* Command::getShell(){
	return mShell;
}

wstring Command::getResult(){
	return result.str();
}

void Command::appendResult(wstring res){
	result << res;
}

vector<wstring> Command::getArguments(){
	vector<wstring> argumentsWithoutRedirection;
	for (vector<wstring>::iterator it = arguments.begin(); it != arguments.end() && *it != L">>" && *it != L">"; it++){
		argumentsWithoutRedirection.push_back(*it);
	}
	return argumentsWithoutRedirection;
}

vector<wstring> Command::getParameters(){
	return parameters;
}

bool Command::hasOutputRedirection(){
	if (find(arguments.begin(), arguments.end(), L">") != arguments.end()) {
		return true;
	}

	if (find(arguments.begin(), arguments.end(), L">>") != arguments.end()) {
		return true;
	}

	return false;
}

void Command::doOutputRedirection(){
	bool overwrite = true;
	vector<wstring>::iterator positionOfRedirectOperator = find(arguments.begin(), arguments.end(), L">");
	if (positionOfRedirectOperator == arguments.end()){
		overwrite = false;
		positionOfRedirectOperator = find(arguments.begin(), arguments.end(), L">>");
	}
	positionOfRedirectOperator++;
	wfstream fs;
	if (overwrite){
		fs.open(*positionOfRedirectOperator, fstream::out);
		fs << getResult();
	}
	else{
		fs.open(*positionOfRedirectOperator, fstream::app);
		wstring s = getResult();
		fs << s;
	}
}

wstring Command::getCommand(){
	return command;
}

wstring Command::getCommandline(){
	return commandline;
}

void Command::parse(wstring line){
	wchar_t currentChar;
	wstring currentToken;
	wstring::iterator it;
	for (it = line.begin(); it != line.end(); it++){
		if (*it == ' '){
			break;
		}
		currentToken += *it;
	}

	command = currentToken;
	wstring restOfString(it, line.end());
	argumentsAndParameters = restOfString;
	currentToken = L"";
	bool startQuotes = false;
	bool isParameter = false;
	for (; it != line.end(); it++){
		if (isParameter && *it == ' '){
			parameters.push_back(currentToken);
			isParameter = false;
			currentToken = L"";
			continue;
		}
		if (*it == '-'){
			isParameter = true;
			continue;
		}
		if (!isParameter && *it == ' ' && !startQuotes){
			if (currentToken != L""){
				arguments.push_back(currentToken);
				
			}
			currentToken = L"";
			continue;
		}
		if (!isParameter && *it == ' ' && startQuotes){
			currentToken += *it;
			continue;
		}
		if (*it == '"'){
			startQuotes = !startQuotes;
			continue;
		}
		currentToken += *it;
		
	}

	if (currentToken != L""){
		if (isParameter){
			parameters.push_back(currentToken);
		}
		else if (!isParameter){
			arguments.push_back(currentToken);
		}
	}
}