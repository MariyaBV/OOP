#include "pch.h"
#include <iostream>

#include "../../../СhangeArray/СhangeArray/ChangeArray.h"

TEST_CASE("FindMinElement test")
{
	std::vector<double> vec1 = {256.256};
	std::vector<double> vec2 = { 1.5, 1.1, 9.2, -15.269 };

	REQUIRE(FindMinElement(vec1) == 256.256);
	REQUIRE(FindMinElement(vec2) == -15.269);
}