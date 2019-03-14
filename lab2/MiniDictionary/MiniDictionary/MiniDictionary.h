#include "pch.h"

using namespace std;

enum class Error
{
	FailedToOpen,
	WordNotFound,
	EmptyFile,
	Ok,
};

Error LoadDictionary(char* fileName, map<string, string>& dictionary);
void PrintMap(const map<string, string>& myMap);
void SaveToFile(char* fileName, map<string, string>& dictionary);
void DialogueWithUser(char* fileName, map<string, string>& dictionary);