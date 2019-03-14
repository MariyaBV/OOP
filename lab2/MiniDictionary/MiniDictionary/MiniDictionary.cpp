#include "pch.h"
#include "MiniDictionary.h"
#include <regex>
#include <type_traits>

Error LoadDictionary(const char* fileName, Dictionary& dictionary)
{
	ifstream inputFile(fileName);

	if (!inputFile.is_open())
	{
		return Error::FailedToOpen;
	}

	if (inputFile.peek() == ifstream::traits_type::eof())
	{
		return Error::EmptyFile;
	}

	string key, val;

	dictionary.clear();
	while (getline(getline(inputFile, key, '|') >> ws, val))
	{
		key = regex_replace(key, regex("^ +| +$|( ) +"), "$1");
		val = regex_replace(val, regex("^ +| +$|( ) +"), "$1");
		dictionary[key] = val;
	}

	inputFile.close();

	return Error::Ok;
}

void PrintDictionary(const Dictionary& dictionary)
{
	for (auto elem : dictionary)
	{
		cout << elem.first << " " << elem.second << endl;
	}
}

string ReadLine()
{
	string word;
	cout << "Введите слово на английском языке(для выхода наберите: ...):\n";
	getline(cin, word);

	return word;
}

void DialogueWithUser(const char* fileName, Dictionary& dictionary, Error err)
{
	string foundTranslation;
	string word;
	string translation;
	bool newWordAdded = false;

	while ((word = ReadLine()) != "...")
	{
		string foundTranslation;

		if (err == Error::Ok)
		{
			foundTranslation = FindTranslation(dictionary, word);
		}

		if (!foundTranslation.empty())
		{
			cout << foundTranslation << endl;
		}
		else
		{
			cout << "Неизвестное слово “" + word + "”. Введите перевод или пустую строку для отказа." << endl;
			getline(cin, translation);
			newWordAdded = SaveOrNotSaveNewWord(dictionary, word, translation);
		}
	};

	char answer;

	if ((word == "...") && (newWordAdded))
	{
		cout << "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом." << endl;

		cin >> answer;

		if ((answer == 'y') || (answer == 'Y') || (answer == 'у') || (answer == 'У'))
		{
			SaveToFile(fileName, dictionary);
		}
	}
}

bool SaveOrNotSaveNewWord(Dictionary dictionary, const string& word, const string& translation)
{
	if (translation.empty())
	{
		cout << "Слово “" + word + "” проигнорировано." << endl;

		return false;
	}
	else
	{

		InsertNewWord(dictionary, word, translation);
		cout << "Слово “" + word + "” сохранено в словаре как “" + translation + "”." << endl;

		return true;
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
