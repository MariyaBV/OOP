#include "pch.h"
#include "../PrimeNumberGenerator/PrimeNumberGenerator.h"

using namespace std;

TEST_CASE("GeneratePrimeNumbersSet test")
{
	CHECK("" == "");

	set<int> primeNumbersSet;

	CHECK(GeneratePrimeNumbersSet(0) == primeNumbersSet);
}