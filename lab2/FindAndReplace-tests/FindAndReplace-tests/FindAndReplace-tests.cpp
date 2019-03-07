#include "pch.h"
#include "../../FindAndReplace/FindAndReplace/FindAndReplace.h"

TEST_CASE("TrimBlanks test")
{
	REQUIRE(FindAndReplace("is is world", "is", "out") == "out out world");
	CHECK(FindAndReplace("hello hello world", "hello", "out") == "out out world");
}