#include "pch.h"
#include "../../../СhangeArray/СhangeArray/ChangeArray.h"
#include <iostream>

TEST_CASE("FindMinElement test")
{
	std::vector<double> vec0 = {};
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

	CHECK_THROWS_AS(FindMinElement(vec0), std::runtime_error);
}

TEST_CASE("ProcessVector test")
{ 
	std::vector<double> vec0 = {};
	std::vector<double> vecOut0 = {};

	std::vector<double> vec1 = { 0, 1, -2, 2 };
	std::vector<double> vecOut1 = { 0, -2, 4, -4 };

	ProcessVector(vec1);
	CHECK(vec1 == vecOut1);

	std::vector<double> vec2 = { 0, 1 };
	std::vector<double> vecOut2 = { 0, 0 };

	ProcessVector(vec2);
	CHECK(vec2 == vecOut2);

	std::vector<double> vec3 = { 0, 1.1, 2, -2.5 };
	std::vector<double> vecOut3 = { 0, -2.75, -5, 6.25 };

	ProcessVector(vec3);
	CHECK(vec3 == vecOut3);

	std::vector<double> vec4 = { 2, 1 };
	std::vector<double> vecOut4 = { 2, 1 };

	ProcessVector(vec4);
	CHECK(vec4 == vecOut4);
}

