#include "pch.h"
#include "../FindMax/FindMax.h"

using namespace std;

SCENARIO("FindMax")
{
	GIVEN("vector with values")
	{
		WHEN("empty vector")
		{
			int maxValue;
			vector<int> intVector = {};
			FindMax(intVector, maxValue);
			CHECK_FALSE(FindMax(intVector, maxValue));
		}
		AND_WHEN("int values")
		{
			int maxValue;
			vector<int> intVector = { 1, 0, 25, 158, -5 };
			CHECK(FindMax(intVector, maxValue));
			CHECK(maxValue == 158);
		}
		AND_WHEN("double values")
		{
			double maxValue;
			vector<double> doubleVector = { 1.2569, 1.2571, 0.25, 1.025, -5.256 };
			CHECK(FindMax(doubleVector, maxValue));
			CHECK(maxValue == 1.2571);
		}
		AND_WHEN("string values")
		{
			string maxValue;
			vector<string> stringVector = { "привет", "a", "b", "c", "d", "пока" };
			CHECK(FindMax(stringVector, maxValue));
			CHECK(maxValue == "привет");
		}
		AND_WHEN("const char*")
		{
			const char* maxValue;
			vector<const char*> charVector = { "qw", "ab", "nt", "qa" };
			CHECK(FindMax(charVector, maxValue));
			CHECK(maxValue == "qw");
		}
		AND_WHEN("empty const char*")
		{
			const char* maxValue;
			vector<const char*> charVector = { };
			CHECK_FALSE(FindMax(charVector, maxValue));
		}
	}
}