#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Error
{
	EmptyString,
	FailedToOpen,
	TextNotFound,
	Ok,
};

Error FindTextInFile(char* fileName, string searchStr, vector<int>& lineNumbers)
{
	ifstream inputFile(fileName);
	Error err = Error::Ok;

	if (!inputFile.is_open())
	{
		return err = Error::FailedToOpen;
	}

	if (searchStr.empty())
	{
		return err = Error::EmptyString;
	}

	string inputFileString;
	size_t position; //size_t - целочисленный беззнаковый тип результата
	int inputFileStringNumber = 0;

	while (getline(inputFile, inputFileString))
	{
		position = inputFileString.find(searchStr);
		inputFileStringNumber++;
		//npos - равное максимальному значению, которое может предоставить тип size_type
		//используется либо как индикатор конца строки в функциях, которые ожидают позицию символа,
		//либо как индикатор ошибки в функциях, которые возвращают позицию в строке
		if (position != string::npos)
		{
			lineNumbers.push_back(inputFileStringNumber);
		}
	}

	if (lineNumbers.empty())
	{
		return err = Error::TextNotFound;
	}

	inputFile.close();

	return err;
}

bool PrintError(char* fileName, Error error)
{
	if (error == (Error::FailedToOpen))
	{
		cout << "Failed to open " << fileName << " for reading" << endl;

		return 1;
	}
	else if (error == (Error::EmptyString))
	{
		cout << "Empty string" << endl;

		return 1;
	}
	else if (error == (Error::TextNotFound))
	{
		cout << "Text not found" << endl;

		return 1;
	}
		
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	char* fileName = argv[1];
	string searchString = argv[2];
	vector<int> lineNumbers;

	if (auto err = FindTextInFile(fileName, searchString, lineNumbers); err != Error::Ok)
	{
		PrintError(fileName, err);

		return 1;
	}
	else
	{
		for (int lineNumber : lineNumbers)
		{
			cout << lineNumber << endl;
		}
	}

	return 0;
}
