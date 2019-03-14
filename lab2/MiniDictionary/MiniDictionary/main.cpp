#include "pch.h"
#include "MiniDictionary.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");

	char* fileName = argv[1];
	map<string, string> dictionary;

	Error err = LoadDictionary(fileName, dictionary);
	PrintMap(dictionary);
	DialogueWithUser(fileName, dictionary, err);

	return 0;
}
