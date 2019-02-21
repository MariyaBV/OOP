#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void FindText(ifstream& inputFile, const string searchStr)
{
	string inputFileString;
	bool stringFound = false;
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
			cout << inputFileStringNumber << endl;
			stringFound = true;
		}
	}

	if (!stringFound)
	{
		cout << "Text not found" << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	// Объявили переменную типа ifstream
	// (input file stream, поток для чтения из файла), проинициализировав его
	// именем входного файла
	ifstream input(argv[1]);

	// вызываем метод is_open() у объекта input,
	// который вернет true, если файл был открыт
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading" << endl;
		return 1;
	}

	string searchString = argv[2];

	if (searchString.empty())
	{
		cout << "Empty string" << endl;
		return 1;
	}

	FindText(input, searchString);

	return 0;
}
