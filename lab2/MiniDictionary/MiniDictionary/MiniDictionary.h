#include "pch.h"

using namespace std;

enum class Error
{
	FailedToOpen,
	WordNotFound,
	EmptyFile,
	Ok,
};

Error LoadDictionary(const char* fileName, map<string, string>& dictionary);
void PrintMap(const map<string, string>& myMap);
void SaveToFile(const char* fileName, map<string, string>& dictionary);
void DialogueWithUser(const char* fileName, map<string, string>& dictionary, Error err);
string FindTranslate(map<string, string>& dictionary, string searchWord, Error err);
void InsertNewWord(map<string, string>& dictionary, string searchWord, string translate);