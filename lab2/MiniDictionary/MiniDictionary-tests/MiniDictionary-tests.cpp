#include "pch.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../MiniDictionary/MiniDictionary.h"

TEST_CASE("FindTranslate and InsertNewWord test")
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
	Error errOk = Error::Ok;
	const char* fileName = { "dictionaryTest.txt" };
	Dictionary dictionary2;
	Dictionary dictionary1 = {
		{ "cat", "koshka" },
		{ "dog", "sobaka" },
		{ "world", "mir" },
		{ "word", "slovo" }
	};

	SaveToFile(fileName, dictionary1);
	Error err2 = LoadDictionary(fileName, dictionary2);

	CHECK(err2 == errOk);
	CHECK(dictionary2["cat"] == "koshka");
	CHECK(dictionary2["dog"] == "sobaka");
	CHECK(dictionary2["world"] == "mir");
	CHECK(dictionary2["word"] == "slovo");
}
