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

TEST_CASE("ProcessVector test")
{
	std::vector<double> vec1 = { 1.5, 1.1, 9.2, -15.269 };
	std::vector<double> vecOut1 = { -22.9, -16.8, 140.47, 233.14 };

	ProcessVector(vec1);
	REQUIRE(vec1 == vecOut1);
}