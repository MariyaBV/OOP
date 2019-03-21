#include "pch.h"
#include "PrimeNumberGenerator.h"
#include <boost/timer.hpp>

using namespace std;
const int MAX_UPPER_BOUND = 100000000;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: PrimeNumberGenerator.exe <unsigned upper bound>" << endl;

		return 1;
	}

	unsigned long upperBound = stoul(argv[1]); //fabs(atoi());

	if (upperBound > MAX_UPPER_BOUND)
	{
		cout << "Invalid upper bound\n"
			 << "Usage: upper bound < " << MAX_UPPER_BOUND << endl;

		return 1;
	}

	/*boost::timer time;
	time.restart();

	GeneratePrimeNumbersSet(upperBound);

	double duration = time.elapsed();
	cout << duration << endl;*/
	PrintPrimeNumbersSet(GeneratePrimeNumbersSet(upperBound));

	return 0;
}