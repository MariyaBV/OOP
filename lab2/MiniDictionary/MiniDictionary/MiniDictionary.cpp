#include "pch.h"
#include "MiniDictionary.h"
#include <type_traits>

using namespace std;

Error LoadDictionary(char* fileName, map<string, string> & dictionary)
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

void PrintMap(const map<string, string>& myMap)
{
	for (auto elem : myMap)
	{
		std::cout << elem.first << " " << elem.second << endl;
	}
}

void DialogueWithUser(char* fileName, map<string, string>& dictionary, Error err)
{
	string searchWord;
	string translate;
	bool newWordAdded = false;

	cout << "Введите слово на английском языке(для выхода наберите: ...):\n";
	getline(cin, searchWord);

	string foundTranslation;

	while (searchWord != "...")
	{ 
		if (err == Error::Ok)
		{
			foundTranslation = FindTranslate(dictionary, searchWord);
		}

		if (!foundTranslation.empty())
		{
			cout << foundTranslation << endl;
		}
		else
		{
			cout << "Неизвестное слово “" + searchWord + "”. Введите перевод или пустую строку для отказа." << endl;
			getline(cin, translate);

			if (translate.empty())
			{
				cout << "Слово “" + searchWord + "” проигнорировано." << endl;
			}
			else
			{
				
				InsertNewWord(dictionary, searchWord, translate);
				cout << "Слово “" + searchWord + "” сохранено в словаре как “" + translate + "”." << endl;
				newWordAdded = true;
			}
		}

		cout << "Введите слово на английском языке(для выхода наберите: ...):\n";
		getline(cin, searchWord);
	};

	char answer;

	if ((searchWord == "...") && (newWordAdded))
	{
		cout << "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом." << endl;

		cin >> answer;

		if ((answer == 'y') || (answer == 'Y') || (answer == 'у') || (answer == 'У'))
		{
			SaveToFile(fileName, dictionary);
		}
	}
}

string FindTranslate(map<string, string>& dictionary, string searchWord)
{
	string translate = dictionary.find(searchWord)->second;

	return translate;
}

void InsertNewWord(map<string, string>& dictionary, string searchWord, string translate)
{
	dictionary.insert({searchWord, translate});
}

void SaveToFile(char* fileName, map<string, string>& dictionary)
{
	ofstream out(fileName);

	for (map<string, string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
	{
		out << i->first << " | " << i->second << endl;
	}
}
