#include "pch.h"

//template <typename T>
//T FindMax(T const& a, T const& b)
//{
//	return (a > b) ? a : b;
//}

template <typename T>
bool FindMax(std::vector<T> const& arr, T& maxValue)
{
	if (arr.size() < 1)
	{
		return false;
	}

	maxValue = arr[0];

	for (size_t i = 0; i < arr.size(); i++)
		if (arr[i] > maxValue)
			maxValue = arr[i];

	return true;
}

template <>
bool FindMax<const char*>(std::vector<const char*> const& arr, const char*& maxValue)
{
	if (arr.size() < 1)
	{
		return false;
	}
	maxValue = arr[0];

	for (size_t i = 0; i < arr.size(); i++)
		if (strcmp(arr[i], maxValue) > 0)
			maxValue = arr[i];

	return true;
}
