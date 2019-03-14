#include "pch.h"
#include "MiniDictionary.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");

	char* fileName = argv[1];
	Dictionary dictionary;

	Error err = LoadDictionary(fileName, dictionary);
	DialogueWithUser(fileName, dictionary, err);

	return 0;
}
