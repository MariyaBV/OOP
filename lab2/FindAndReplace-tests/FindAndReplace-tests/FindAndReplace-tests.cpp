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
