#include "pch.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../MiniDictionary/MiniDictionary.h"

TEST_CASE("FindTranslate test")
{
	CHECK("" == "");

	Dictionary dictionary = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
	};

	string searchWord1 = "dog";
	CHECK(FindTranslation(dictionary, searchWord1) == "собака");

	string searchWord2 = "hello";
	CHECK(FindTranslation(dictionary, searchWord2) == "");
}

TEST_CASE("InsertNewWord test")
{
	Dictionary dictionary = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
	};
	string searchWord3 = "hello";
	string translate3 = "привет";
	Dictionary dictionaryOut = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
		{ "hello", "привет" },
	};

	InsertNewWord(dictionary, searchWord3, translate3);

	CHECK(dictionary == dictionaryOut);
}

TEST_CASE("LoadDictionary and SaveToFile test")
{
	const char* fileName0 = "1.txt";
	Dictionary dictionary0;
	Error err0 = LoadDictionary(fileName0, dictionary0);
	CHECK(err0 == Error::FailedToOpen);

	const char* fileName1 = "2.txt";
	Dictionary dictionary1;
	Error err1 = LoadDictionary(fileName1, dictionary1);
	CHECK(err1 == Error::EmptyFile);

	const char* fileName3 = "dictionaryTest.txt";
	Dictionary dictionary3;
	Dictionary dictionary33 = {
		{ "cat", "koshka" },
		{ "dog", "sobaka" },
		{ "world", "mir" },
		{ "word", "slovo" }
	};

	SaveToFile(fileName3, dictionary33);
	LoadDictionary(fileName3, dictionary3);

	CHECK(dictionary3["cat"] == "koshka");
	CHECK(dictionary3["dog"] == "sobaka");
	CHECK(dictionary3["world"] == "mir");
	CHECK(dictionary3["word"] == "slovo");

	// проверка работы dictionary.clear();
	const char* fileName4 = "dictionary1.txt";
	LoadDictionary(fileName4, dictionary3);

	CHECK(dictionary3["computer"] == "komputer");
	CHECK(dictionary3.size() == 1);
}
