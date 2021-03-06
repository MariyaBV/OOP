#include "pch.h"
#include "MiniDictionary.h"
#include <regex>
#include <type_traits>

void LoadDictionary(const char* fileName, Dictionary& dictionary)
{
	ifstream inputFile(fileName);
	string key, val;

	dictionary.clear();
	while (getline(getline(inputFile, key, '|') >> ws, val))
	{
		key = regex_replace(key, regex("^ +| +$|( ) +"), "$1");
		val = regex_replace(val, regex("^ +| +$|( ) +"), "$1");
		dictionary[key] = val;
	}

	inputFile.close();
}

string ReadLine(string dialogue)
{
	string word;
	cout << dialogue << endl;
	getline(cin, word);

	if (cin.eof() == 1)
	{
		cin.clear();
		cin.ignore();
	}

	return word;
}

void DialogueWithUser(const char* fileName, Dictionary& dictionary)
{
	string foundTranslation;
	string word;
	string translation;
	bool newWordAdded = false;

	while ((word = ReadLine("Введите слово на английском языке(для выхода наберите: ...):")) != "...")
	{
		string foundTranslation;

		foundTranslation = FindTranslation(dictionary, word);

		if (!foundTranslation.empty())
		{
			cout << foundTranslation << endl;
		}
		else
		{
			translation = ReadLine("Неизвестное слово “" + word + "”. Введите перевод или пустую строку для отказа.");

			if (translation.empty())
			{
				cout << "Слово “" + word + "” проигнорировано." << endl;
			}
			else
			{
				InsertNewWord(dictionary, word, translation);
				cout << "Слово “" + word + "” сохранено в словаре как “" + translation + "”." << endl;
				newWordAdded = true;
			}
		}
	};

	OutOfDialogue(word, newWordAdded, dictionary, fileName);
}

void OutOfDialogue(string word, bool newWordAdded, const Dictionary& dictionary, const char* fileName)
{
	char answer;

	if ((word == "...") && (newWordAdded))
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения, n или N для выхода без сохранения." << endl;
		cin >> answer;

		if ((answer == 'y') || (answer == 'Y') || (answer == 'у') || (answer == 'У'))
		{
			SaveToFile(fileName, dictionary);
		}
	}
}

string FindTranslation(const Dictionary& dictionary, const string& word)
{
	string foundTranslation;
	auto foundPosition = dictionary.find(word);

	if (foundPosition != dictionary.end())
	{
		foundTranslation = foundPosition->second;
	}

	return foundTranslation;
}

void InsertNewWord(Dictionary& dictionary, const string& word, const string& translation)
{
	dictionary.emplace(word, translation);
}

void SaveToFile(const char* fileName, const Dictionary& dictionary)
{
	ofstream out(fileName);

	for (const auto& item : dictionary)
	{
		out << item.first << " | " << item.second << endl;
	}

	out.close();
}
