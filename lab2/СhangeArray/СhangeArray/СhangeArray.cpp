#include "pch.h"
#include "ChangeArray.h"
#include <iterator>

void ReadVectorFromStream(std::istream& input, std::vector<double>& vector)
{
	double number;
	while (input >> number)
	{
		vector.push_back(number);
	}
}

double FindMinElement(const std::vector<double>& vector)
{
	if (!vector.empty())
	{
		double min = *min_element(vector.begin(), vector.end());
		return min;
	}
	else
	{
		throw "Empty vector";
	}
}

void ProcessVector(std::vector<double>& vector)
{
	double minElemet = FindMinElement(vector);
	for (double item : vector)
	{
		item *= minElemet;
	}
}

void PrintVector(const std::vector<double> vector)
{
	copy(vector.begin(), vector.end(), std::ostream_iterator<double>(std::cout, " "));
}
