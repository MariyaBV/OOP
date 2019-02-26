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

Error FindTextInFile(char* input, string searchStr, vector<int>& numberOfStr)
{
	ifstream inputFile(input);
	string inputFileString;
	size_t position; //size_t - целочисленный беззнаковый тип результата
	Error err = Error::Ok;
	int inputFileStringNumber = 0;

	if (!inputFile.is_open())
	{
		return err = Error::FailedToOpen;
	}

	if (searchStr.empty())
	{
		return err = Error::EmptyString;
	}

	while (getline(inputFile, inputFileString))
	{
		position = inputFileString.find(searchStr);
		inputFileStringNumber++;
		//npos - равное максимальному значению, которое может предоставить тип size_type
		//используется либо как индикатор конца строки в функциях, которые ожидают позицию символа,
		//либо как индикатор ошибки в функциях, которые возвращают позицию в строке
		if (position != string::npos)
		{
			numberOfStr.push_back(inputFileStringNumber);
		}
	}

	if (numberOfStr.empty())
	{
		return err = Error::TextNotFound;
	}

	return err;
}

bool PrintAnswer(char* input, string searchStr, vector<int>& numberOfStr)
{
	Error error = FindTextInFile(input, searchStr, numberOfStr);

	if (error == (Error::Ok))
	{
		for (int number : numberOfStr)
		{
			cout << number << endl;
		}
	}
	else if (error == (Error::FailedToOpen))
	{
		cout << "Failed to open " << input << " for reading" << endl;

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

	char* input = argv[1];
	string searchString = argv[2];
	vector<int> numberOfStr;

	return PrintAnswer(input, searchString, numberOfStr);
}
