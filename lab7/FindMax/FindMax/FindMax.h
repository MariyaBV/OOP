#pragma once

template <typename T>
bool FindMax(std::vector<T> const& arr, T& maxValue)
{
	if (arr.empty())
	{
		return false;
	}

	size_t indexOfMaxValue = 0;

	for (size_t i = 0; i < arr.size(); i++)
	{
		if(arr[indexOfMaxValue] < arr[i])
			indexOfMaxValue = i;
	}

	maxValue = arr[indexOfMaxValue];

	return true;
}

template <>
bool FindMax<const char*>(std::vector<const char*> const& arr, const char*& maxValue)
{
	if (arr.empty())
	{
		return false;
	}
	maxValue = arr[0];

	for (size_t i = 0; i < arr.size(); i++)
		if (strcmp(arr[i], maxValue) > 0)
			maxValue = arr[i];

	return true;
}
