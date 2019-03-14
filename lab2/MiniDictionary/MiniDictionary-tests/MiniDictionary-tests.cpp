#include "pch.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../MiniDictionary/MiniDictionary.h"

TEST_CASE("LoadDictionary test")
{
	CHECK("" == "");
	map<string, string> dictionary = {
		{ "cat", "кошка" },
		{ "dog", "собака" },
	};
	string searchWord1 = "dog";

	CHECK(FindTranslate(dictionary, searchWord1) != dictionary.end());
	CHECK(FindTranslate(dictionary, searchWord1)->second == "собака");

	string searchWord2 = "hello";
	CHECK(FindTranslate(dictionary, searchWord2) == dictionary.end());
}