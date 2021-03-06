#include "pch.h"
#include "../../FindAndReplace/FindAndReplace/FindAndReplace.h"

TEST_CASE("FindAndReplace test")
{
	CHECK("" == "");
	CHECK(FindAndReplace("", "is", "out") == "");
	CHECK(FindAndReplace("is is world", "", "out") == "is is world");
	CHECK(FindAndReplace("is is world", "is", "") == "  world");
	CHECK(FindAndReplace("is is world", "hello", "out") == "is is world");
	CHECK(FindAndReplace("is is world", "is", "is") == "is is world");
	CHECK(FindAndReplace("is is world", "is", "out") == "out out world");
	CHECK(FindAndReplace("hello hello world", "hello", "out") == "out out world");
	CHECK(FindAndReplace("hel hel world", "hel", "out") == "out out world");
}
