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
	string searchWord = "hello";
	string translate = "привет";
	Dictionary dictionaryOut = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
		{ "hello", "привет" },
	};

	InsertNewWord(dictionary, searchWord, translate);

	CHECK(dictionary == dictionaryOut);
}

TEST_CASE("LoadDictionary and SaveToFile test")
{
	const char* fileName1 = "dictionaryTest.txt";
	Dictionary dictionary1;
	Dictionary dictionary11 = {
		{ "cat", "koshka" },
		{ "dog", "sobaka" },
		{ "world", "mir" },
		{ "word", "slovo" }
	};

	SaveToFile(fileName1, dictionary11);
	LoadDictionary(fileName1, dictionary1);

	CHECK(dictionary1["cat"] == "koshka");
	CHECK(dictionary1["dog"] == "sobaka");
	CHECK(dictionary1["world"] == "mir");
	CHECK(dictionary1["word"] == "slovo");

	// проверка работы dictionary.clear();
	const char* fileName2 = "dictionary1.txt";
	LoadDictionary(fileName2, dictionary1);

	CHECK(dictionary1["computer"] == "komputer");
	CHECK(dictionary1.size() == 1);
}
