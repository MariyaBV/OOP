#include "pch.h"
#include <algorithm>
#include <boost/multi_array.hpp>
#include <functional>
#include <iostream>
#include <vector>

void ReadVectorFromStream(std::istream& input, std::vector<double>& vector)
{
	double number;
	while (input >> number)
	{
		vector.push_back(number);
	}
}

double FindMinElement(std::vector<double>& vector)
{
	double min = *min_element(vector.begin(), vector.end());

	return min;
}

void ProcessVector(std::vector<double>& vector)
{
	double minElemet = FindMinElement(vector);
	for (size_t i = 0; i < vector.size(); i++)
	{
		vector[i] *= minElemet;
	}
}

void PrintVector(const std::vector<double> vector)
{
	copy(vector.begin(), vector.end(), std::ostream_iterator<double>(std::cout, " "));
}
