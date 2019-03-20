#include "pch.h"
#include "PrimeNumberGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(const unsigned int upperBound)
{
	vector<bool> prime(upperBound + 1, true);
	set<int> primeNumbers;

	prime[0] = prime[1] = false;
	for (unsigned int i = 2; i * i <= upperBound; ++i) // valid for n < 46340^2 = 2147395600
		if (prime[i])
		{
			primeNumbers.insert(i);

			for (unsigned int j = i + i; j <= upperBound; j += i)
				prime[j] = false;
		}
	
	return primeNumbers;
}

void PrintPrimeNumbersSet(const set<int> PrimeNumbersSet)
{
	copy(PrimeNumbersSet.begin(), PrimeNumbersSet.end(), ostream_iterator<int>(cout, " "));
}
