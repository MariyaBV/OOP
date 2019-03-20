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

void LoadDictionary(const char* fileName, Dictionary& dictionary);
void SaveToFile(const char* fileName, const Dictionary& dictionary);
void DialogueWithUser(const char* fileName, Dictionary& dictionary);
string FindTranslation(const Dictionary& dictionary, const string& searchWord);
void InsertNewWord(Dictionary& dictionary, const string& searchWord, const string& translate);
void OutOfDialogue(string word, bool newWordAdded, const Dictionary& dictionary, const char* fileName);
