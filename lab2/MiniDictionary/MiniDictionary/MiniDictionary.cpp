#include "pch.h"
#include "MiniDictionary.h"
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

	while (getline(getline(inputFile, key, '|') >> ws, val))
	{
		dictionary[key] = val;
	}
	
	inputFile.close();

	return Error::Ok;
}

void PrintDictionary(const Dictionary& myMap)
{
	for (auto elem : myMap)
	{
		std::cout << elem.first << " " << elem.second << endl;
	}
}

void DialogueWithUser(const char* fileName, Dictionary& dictionary, Error err)
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

string FindTranslation(Dictionary& dictionary, const string& word)
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

void SaveToFile(const char* fileName, Dictionary& dictionary)
{
	ofstream out(fileName);

	for (Dictionary::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
	{
		out << i->first << " | " << i->second << endl;
	}
}
