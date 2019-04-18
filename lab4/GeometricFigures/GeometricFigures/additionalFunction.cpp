#include "pch.h"

uint32_t FromStringToUINT32(std::string& outlineColor)
{
	std::istringstream reader(outlineColor);
	uint32_t color = 0;

	reader >> std::hex >> color;

	return color;
}

bool IsEqual(double const first, double const second)
{
	static double eps = 1e-5;

	return fabs(first - second) < eps;
}
