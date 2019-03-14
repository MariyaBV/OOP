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
void PrintDictionary(const Dictionary& dictionary);
void SaveToFile(const char* fileName, const Dictionary& dictionary);
void DialogueWithUser(const char* fileName, Dictionary& dictionary, Error err);
string FindTranslation(const Dictionary& dictionary, const string& searchWord);
void InsertNewWord(Dictionary& dictionary, const string& searchWord, const string& translate);
bool SaveOrNotSaveNewWord(Dictionary dictionary, const string& word, const string& translation);