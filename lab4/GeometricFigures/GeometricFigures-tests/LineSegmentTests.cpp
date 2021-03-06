#include "pch.h"
#include "../GeometricFigures/CLineSegment.h"
#include "../GeometricFigures/AdditionalFunction.h"

SCENARIO("Line Segment")
{
	GIVEN("2 points and color")
	{
		CPoint startPoint = { 0.0, 1.0 };
		CPoint endPoint = { 2.0, 3.0 };

		WHEN("2 points, no color specified") 
		{
			std::string outlineColor;
			CLineSegment lineSegment(startPoint, endPoint, outlineColor);

			THEN("get area")
			{
				CHECK(lineSegment.GetArea() == 0);
			}
			AND_THEN("get perimetr")
			{
				CHECK(IsEqual(lineSegment.GetPerimeter(),2.82843));
			}
			AND_THEN("get outline color")
			{
				CHECK(lineSegment.GetOutlineColor() == 000000);
			}
			AND_THEN("start point")
			{
				CHECK(lineSegment.GetStartPoint().x == 0);
				CHECK(lineSegment.GetStartPoint().y == 1);
			}
			AND_THEN("end point") 
			{
				CHECK(lineSegment.GetEndPoint().x == 2);
				CHECK(lineSegment.GetEndPoint().y == 3);
			}
			AND_THEN("information")
			{
				auto str1 = "LineSegment:\n"
							"\tarea = 0.00\n"
							"\tperimeter = 2.83\n"
							"\toutline color = 000000\n"
							"\tstart point(0.00, 1.00)\n"
							"\tend point(2.00, 3.00)\n";

				CHECK(lineSegment.ToString() == str1);
			}
		}
		AND_WHEN("2 points and color")
		{
			std::string outlineColor = "FFFF00";
			uint32_t color = FromStringToUINT32(outlineColor);
			CLineSegment lineSegment(startPoint, endPoint, outlineColor);
			auto str2 = "LineSegment:\n"
						"\tarea = 0.00\n"
						"\tperimeter = 2.83\n"
						"\toutline color = ffff00\n"
						"\tstart point(0.00, 1.00)\n"
						"\tend point(2.00, 3.00)\n";

			THEN("get area")
			{
				CHECK(lineSegment.GetArea() == 0);
			}
			AND_THEN("get perimetr")
			{
				CHECK(IsEqual(lineSegment.GetPerimeter(), 2.82843));
			}
			AND_THEN("get outline color")
			{
				CHECK(lineSegment.GetOutlineColor() == color);
			}
			AND_THEN("start point")
			{
				CHECK(lineSegment.GetStartPoint().x == 0);
				CHECK(lineSegment.GetStartPoint().y == 1);
			}
			AND_THEN("end point")
			{
				CHECK(lineSegment.GetEndPoint().x == 2);
				CHECK(lineSegment.GetEndPoint().y == 3);
			}
			AND_THEN("information")
			{
				/*auto str1 = "LineSegment:\n"
							"\tarea = 0.00\n"
							"\tperimeter = 0.00\n"
							"\toutline color = 000000\n"
							"\tstart point(0.00, 1.00)\n"
							"\tend point(2.00, 3.00)\n";*/

				CHECK(lineSegment.ToString() == str2);
			}
		}
		
	}
}