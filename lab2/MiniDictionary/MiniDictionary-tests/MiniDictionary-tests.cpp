#include "pch.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../MiniDictionary/MiniDictionary.h"

TEST_CASE("FindTranslate and InsertNewWord test")
{
	CHECK("" == "");

	map<string, string> dictionary = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
	};

	string searchWord1 = "dog";
	CHECK(FindTranslation(dictionary, searchWord1) == "собака");

	string searchWord2 = "hello";
	CHECK(FindTranslation(dictionary, searchWord2) == "");

	string searchWord3 = "hello";
	string translate3 = "привет";
	map<string, string> dictionaryOut = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
		{ "hello", "привет" },
	};
	InsertNewWord(dictionary, searchWord3, translate3);
	CHECK(dictionary == dictionaryOut);
}

TEST_CASE("LoadDictionary and DialogueWithUser test")
{
	const char* fileName = "dictionary.txt";
	map<string, string> dictionary;
	Error errOk = Error::Ok;
	Error err1 = LoadDictionary(fileName, dictionary);
	CHECK(err1 == errOk);

	const char* fileName2 = { "dictionaryTest.txt" };
	map<string, string> dictionaryTest = {
		{ "cat", "koshka" },
		{ "dog", "sobaka" },
		{ "world", "mir" },
	};
	SaveToFile(fileName2, dictionaryTest);
	Error err2 = LoadDictionary(fileName2, dictionaryTest);
	CHECK(err2 == errOk);
}
