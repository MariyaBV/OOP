#include "pch.h"
#include "../../../СhangeArray/СhangeArray/ChangeArray.h"
#include <iostream>

TEST_CASE("FindMinElement test")
{
	//empty vector
	std::vector<double> vec0 = {};
	CHECK_THROWS_AS(FindMinElement(vec0), std::runtime_error);

	//min из одинаковых
	std::vector<double> vec1 = { 25, 25 };
	CHECK(FindMinElement(vec1) == 25);

	//min < 0
	std::vector<double> vec2 = { 1.5, 1.1, 9.2, -15.269 };
	CHECK(FindMinElement(vec2) == -15.269);

	//min = 0
	std::vector<double> vec3 = { 1.5, 1.1, 9.2, 0 };
	CHECK(FindMinElement(vec3) == 0);

	//min > 0
	std::vector<double> vec4 = { 1.5, 1.1, 9.2 };
	CHECK(FindMinElement(vec4) == 1.1);

	//min из 1-го
	std::vector<double> vec5 = { 1 };
	CHECK(FindMinElement(vec5) == 1);
}

TEST_CASE("ProcessVector test")
{ 
	//empty vector
	std::vector<double> vec0 = {};
	std::vector<double> vecOut0 = {};

	ProcessVector(vec0);
	CHECK(vec0 == vecOut0);

	//изменения на min < 0
	std::vector<double> vec1 = { 0, 1.1, 2, -2.5 };
	std::vector<double> vecOut1 = { 0, -2.75, -5, 6.25 };

	ProcessVector(vec1);
	CHECK(vec1 == vecOut1);

	//изменения на min = 0
	std::vector<double> vec2 = { 0, 1 };
	std::vector<double> vecOut2 = { 0, 0 };

	ProcessVector(vec2);
	CHECK(vec2 == vecOut2);

	//изменения на min > 0
	std::vector<double> vec4 = { 2, 1 };
	std::vector<double> vecOut4 = { 2, 1 };

	ProcessVector(vec4);
	CHECK(vec4 == vecOut4);
}

