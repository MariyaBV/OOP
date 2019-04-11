#include "pch.h"

uint32_t FromStringToUINT32(std::string& outlineColor)
{
	std::istringstream reader(outlineColor);
	uint32_t color = 0;

	reader >> color;

	return color;
}