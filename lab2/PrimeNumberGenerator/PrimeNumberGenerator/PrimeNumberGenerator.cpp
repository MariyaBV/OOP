#include "pch.h"
#include <iostream>
#include "PrimeNumberGenerator.h"

using namespace std;

set<int> GeneratePrimeNumbersSet(const unsigned long upperBound)
{
	vector<bool> prime(upperBound + 1, true);
	set<int> primeNumbers;

	if (upperBound > 1)
	{
		prime[0] = prime[1] = false;
		if (upperBound >= 2)
		{
			prime[2] = true;
			primeNumbers.insert(2);
		}
		
		for (unsigned int i = 4; i <= upperBound; i += 2)
		{
			prime[i] = false;
		}
		
		for (unsigned int i = 3; i <= upperBound; i += 2)
			if (prime[i] == true)
			{
				primeNumbers.insert(i);

				for (unsigned int j = i + i; j <= upperBound; j += i)
					prime[j] = false;
			}
	}
	
	return primeNumbers;
}

void PrintSet(const set<int> PrimeNumbersSet)
{
	for (set<int>::iterator it = PrimeNumbersSet.begin(); it != PrimeNumbersSet.end(); ++it)
		cout << ' ' << *it;
}
