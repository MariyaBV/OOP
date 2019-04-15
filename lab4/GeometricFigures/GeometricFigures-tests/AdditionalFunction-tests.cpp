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

TEST_CASE("is equal")
{
	CHECK_FALSE(IsEqual(1.0001, 1.0002));
	CHECK(IsEqual(1.00123, 1.001234));
	CHECK(IsEqual(1.001237, 1.001235));
}