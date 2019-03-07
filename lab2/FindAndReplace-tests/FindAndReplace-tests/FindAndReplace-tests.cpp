#include "pch.h"
#include "../../FindAndReplace/FindAndReplace/FindAndReplace.h"

TEST_CASE("FindAndReplace test")
{
	CHECK("" == ""); 
	CHECK(FindAndReplace("is is world", "is", "out") == "out out world");
	CHECK(FindAndReplace("hello hello world", "hello", "out") == "out out world");
	CHECK(FindAndReplace("hel hel world", "hel", "out") == "out out world");
	CHECK(FindAndReplace("hel hel world", "is", "out") == "hel hel world");
}

TEST_CASE("FindError test")
{
	std::string notEmptystring = "hello", emptyString = "";

	Error err1 = FindError(emptyString, notEmptystring);
	CHECK(err1 == Error::EmptyReplaceString);

	Error err2 = FindError(notEmptystring, emptyString);
	CHECK(err2 == Error::EmptySearchString);
}