#include "pch.h"
#include "MiniDictionary.h"
#include <type_traits>

using namespace std;

Error LoadDictionary(const char* fileName, map<string, string> & dictionary)
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

	while (getline(getline(inputFile, key, '|') >> ws, val))
	{
		dictionary[key] = val;
	}
	
	inputFile.close();

	return Error::Ok;
}

void PrintDictionary(const map<string, string>& myMap)
{
	for (auto elem : myMap)
	{
		std::cout << elem.first << " " << elem.second << endl;
	}
}

void DialogueWithUser(const char* fileName, map<string, string>& dictionary, Error err)
{
	string word;
	string translation;
	bool newWordAdded = false;

	cout << "Введите слово на английском языке(для выхода наберите: ...):\n";
	getline(cin, word);

	string foundTranslation;

	while (word != "...")
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

		cout << "Введите слово на английском языке(для выхода наберите: ...):\n";
		getline(cin, word);
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

string FindTranslation(map<string, string>& dictionary, string word)
{
	string foundTranslation;
	auto iteratorFind = dictionary.find(word);

	if (iteratorFind != dictionary.end())
	{
		foundTranslation = iteratorFind->second;
	}

	return foundTranslation;
}

void InsertNewWord(map<string, string>& dictionary, string word, string translation)
{
	dictionary.insert({ word, translation });
}

void SaveToFile(const char* fileName, map<string, string>& dictionary)
{
	ofstream out(fileName);

	for (map<string, string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
	{
		out << i->first << " | " << i->second << endl;
	}
}
