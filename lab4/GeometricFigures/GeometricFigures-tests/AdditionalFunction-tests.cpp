#include "pch.h"
#include "../GeometricFigures/AdditionalFunction.h"

TEST_CASE("from string to uint32_t")
{
	std::string color = "FFFF00";
	std::string color2 = "0x" + color;
	uint32_t colorUINT = 0xFFFF00;
	uint32_t value = strtoul(color2.c_str(), NULL, 10);
	std::cout << "!!!!!!!     " << "0x" << std::hex << std::setfill('0') << std::setw(2) << std::right << value << std::endl;
	CHECK(FromStringToUINT32(color2) == colorUINT);
}