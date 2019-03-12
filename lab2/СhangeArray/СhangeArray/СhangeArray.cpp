#include "pch.h"
#include "ChangeArray.h"
#include <iterator>

double FindMinElement(const std::vector<double>& vectorOfNumbers)
{
	if (!vectorOfNumbers.empty())
	{
		auto min = min_element(vectorOfNumbers.begin(), vectorOfNumbers.end()); //возвращает итератор на min element

		return *min;//получаем значение min
	}
	else
	{
		throw std::runtime_error("Empty vector of numbers");
	}
}

void ProcessVector(std::vector<double>& vectorOfNumbers)
{
	double minElemet = FindMinElement(vectorOfNumbers);

	for (double& item : vectorOfNumbers)
	{
		item *= minElemet;
	}
}

void PrintVector(const std::vector<double> vectorOfNumbers)
{
	copy(vectorOfNumbers.begin(), vectorOfNumbers.end(), std::ostream_iterator<double>(std::cout, " "));
}
