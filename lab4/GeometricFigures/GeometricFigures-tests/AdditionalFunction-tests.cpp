#include "pch.h"
#include "../GeometricFigures/AdditionalFunction.h"

TEST_CASE("from string to uint32_t")
{
	std::string color1 = "FFFF00";
	uint32_t colorUINT1 = 0xFFFF00;
	CHECK(FromStringToUINT32(color1) == colorUINT1);

	//empty color
	std::string color2;
	uint32_t colorUINT2 = 000000;
	CHECK(FromStringToUINT32(color2) == colorUINT2);
}