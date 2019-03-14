#include "pch.h"

using namespace std;
using Dictionary = map<string, string>;

enum class Error
{
	FailedToOpen,
	WordNotFound,
	EmptyFile,
	Ok,
};

Error LoadDictionary(const char* fileName, Dictionary& dictionary);
void PrintDictionary(const Dictionary& myMap);
void SaveToFile(const char* fileName, Dictionary& dictionary);
void DialogueWithUser(const char* fileName, Dictionary& dictionary, Error err);
string FindTranslation(Dictionary& dictionary, const string& searchWord);
void InsertNewWord(Dictionary& dictionary, const string& searchWord, const string& translate);