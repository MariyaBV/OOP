#include "pch.h"
#include "../PrimeNumberGenerator/PrimeNumberGenerator.h"
#include <iostream>
#include <boost/timer.hpp>

using namespace std;
const int MAX_UPPER_BOUND = 100000000;

TEST_CASE("GeneratePrimeNumbersSet test")
{
	CHECK("" == "");

	set<int> primeNumbersSet0 = {};
	CHECK(GeneratePrimeNumbersSet(0) == primeNumbersSet0);
	CHECK(GeneratePrimeNumbersSet(1) == primeNumbersSet0);

	set<int> primeNumbersSet1 = {2};
	CHECK(GeneratePrimeNumbersSet(2) == primeNumbersSet1);

	set<int> primeNumbersSet2 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
	CHECK(GeneratePrimeNumbersSet(36) == primeNumbersSet2);

	CHECK(GeneratePrimeNumbersSet(1000).size() == 168);

	#if !_DEBUG
		boost::timer time;
		time.restart();
		CHECK(GeneratePrimeNumbersSet(MAX_UPPER_BOUND).size() == 5761455);
		double duration = time.elapsed();
		cout << "duration for " << MAX_UPPER_BOUND << " = " << duration << endl;
	#endif
}