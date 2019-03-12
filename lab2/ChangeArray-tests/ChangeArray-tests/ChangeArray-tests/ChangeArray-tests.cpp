#include "pch.h"
#include <iostream>
#include "../../../СhangeArray/СhangeArray/ChangeArray.h"

TEST_CASE("FindMinElement test")
{
	std::vector<double> vec1 = { 25, 25 };
	std::vector<double> vec2 = { 1.5, 1.1, 9.2, -15.269 };
	std::vector<double> vec3 = { 1.5, 1.1, 9.2, 0 };
	std::vector<double> vec4 = { 1.5, 1.1, 9.2 };
	std::vector<double> vec5 = { 1 };

	CHECK(FindMinElement(vec1) == 25);
	CHECK(FindMinElement(vec2) == -15.269);
	CHECK(FindMinElement(vec3) == 0);
	CHECK(FindMinElement(vec4) == 1.1);
	CHECK(FindMinElement(vec5) == 1);
}

TEST_CASE("ProcessVector test")
{ /*
	std::vector<double> vec1 = { 0, 1, 2, -2 };
	std::vector<double> vecOut1 = { 0, -2, -4, 4 };

	ProcessVector(vec1);
	CHECK(vec1 == vecOut1);*/

	std::vector<double> vec2 = { 0 };
	std::vector<double> vecOut2 = { 0 };

	ProcessVector(vec2);
	CHECK(vec2 == vecOut2);
}