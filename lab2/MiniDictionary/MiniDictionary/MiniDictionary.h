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
void PrintDictionary(const map<string, string>& myMap);
void SaveToFile(const char* fileName, map<string, string>& dictionary);
void DialogueWithUser(const char* fileName, map<string, string>& dictionary, Error err);
string FindTranslation(map<string, string>& dictionary, string searchWord);
void InsertNewWord(map<string, string>& dictionary, string searchWord, string translate);