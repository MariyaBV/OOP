#include "pch.h"
#include "MiniDictionary.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");
	const char* fileName;

	if (argc != 2)
	{
		fileName = "dictionary0.txt";
	}
	else
	{
		fileName = argv[1];
	};

	Dictionary dictionary;

	Error err = LoadDictionary(fileName, dictionary);
	DialogueWithUser(fileName, dictionary);

	return 0;
}
