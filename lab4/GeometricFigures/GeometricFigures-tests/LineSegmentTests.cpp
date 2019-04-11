#include "pch.h"
#include "../GeometricFigures/CLineSegment.h"
#include "../GeometricFigures/AdditionalFunction.h"

SCENARIO("Line Segment")
{
	CPoint startPoint = { 0.0, 1.0 };
	CPoint endPoint = { 2.0, 3.0 };
	std::string outlineColor;
	CLineSegment lineSegment(startPoint, endPoint, outlineColor);
	auto str1 = "LineSegment:\n"
		"\tarea = 0.00\n"
		"\tperimeter = 0.00\n"
		"\toutline color = 000000\n"
		"\tstart point(0.00, 1.00)\n"
		"\tend point(2.00, 3.00)\n";

	GIVEN("2 points and color")
	{
		WHEN("2 points, no color specified") 
		{
			CHECK(lineSegment.GetArea() == 0);
			CHECK(lineSegment.GetPerimeter() == 0);
			CHECK(lineSegment.GetOutlineColor() == 000000);
			CHECK(lineSegment.GetStartPoint().x == 0);
			CHECK(lineSegment.GetStartPoint().y == 1);
			CHECK(lineSegment.GetEndPoint().x == 2);
			CHECK(lineSegment.GetEndPoint().y == 3);
			CHECK(lineSegment.ToString() == str1);
		}
		AND_WHEN("2 points and color")
		{
			std::string outlineColor = "FFFF00";
			uint32_t color = FromStringToUINT32(outlineColor);
			CLineSegment lineSegment(startPoint, endPoint, outlineColor);
			auto str2 = "LineSegment:\n"
						"\tarea = 0.00\n"
						"\tperimeter = 0.00\n"
						"\toutline color = ffff00\n"
						"\tstart point(0.00, 1.00)\n"
						"\tend point(2.00, 3.00)\n";

			CHECK(lineSegment.GetArea() == 0);
			CHECK(lineSegment.GetPerimeter() == 0);
			CHECK(lineSegment.GetOutlineColor() == color);
			CHECK(lineSegment.GetStartPoint().x == 0);
			CHECK(lineSegment.GetStartPoint().y == 1);
			CHECK(lineSegment.GetEndPoint().x == 2);
			CHECK(lineSegment.GetEndPoint().y == 3);
			CHECK(lineSegment.ToString() == str2);
		}
		
	}
}