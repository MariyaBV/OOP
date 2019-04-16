#include "pch.h"
#include "../GeometricFigures/AdditionalFunction.h"
#include "../GeometricFigures/CCircle.h"

SCENARIO("Circle")
{
	GIVEN("radius and center without color")
	{
		double radius = 5;
		CPoint center = { 0.0, 0.0 };

		WHEN("2 points, no color specified")
		{
			std::string outlineColor, fillColor;
			CCircle circle(center, radius, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(IsEqual(circle.GetArea(), 78.53981));
			}
			AND_THEN("get perimetr")
			{
				CHECK(IsEqual(circle.GetPerimeter(), 31.41593));
			}
			AND_THEN("get outline color")
			{
				CHECK(circle.GetOutlineColor() == 000000);
			}
			AND_THEN("get fill color")
			{
				CHECK(circle.GetFillColor() == 000000);
			}
			AND_THEN("center, radius")
			{
				CHECK(circle.GetCenter().x == 0);
				CHECK(circle.GetCenter().y == 0);

				CHECK(circle.GetRadius() == 5);
			}
			AND_THEN("information")
			{
				auto str1 = "Circle:\n"
							"\tarea = 78.54\n"
							"\tperimeter = 31.42\n"
							"\toutline color = 000000\n"
							"\tfill color = 000000\n"
							"\tcenter(0.00, 0.00)\n"
							"\tradius = 5.00\n";

				CHECK(circle.ToString() == str1);
			}
		}
	}

	GIVEN("radius and center with color")
	{
		double radius = 12;
		CPoint center = { 5.0, 10.0 };

		WHEN("2 points, no color specified")
		{
			std::string outlineColor = "ff5566";
			std::string fillColor = "00ff99";
			CCircle circle(center, radius, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(IsEqual(circle.GetArea(), 452.389342));
			}
			AND_THEN("get perimetr")
			{
				CHECK(IsEqual(circle.GetPerimeter(), 75.398224));
			}
			AND_THEN("get outline color")
			{
				CHECK(circle.GetOutlineColor() == FromStringToUINT32(outlineColor));
			}
			AND_THEN("get fill color")
			{
				CHECK(circle.GetFillColor() == FromStringToUINT32(fillColor));
			}
			AND_THEN("center, radius")
			{
				CHECK(circle.GetCenter().x == 5);
				CHECK(circle.GetCenter().y == 10);

				CHECK(circle.GetRadius() == 12);
			}
			AND_THEN("information")
			{
				auto str1 = "Circle:\n"
							"\tarea = 452.39\n"
							"\tperimeter = 75.40\n"
							"\toutline color = ff5566\n"
							"\tfill color = 00ff99\n"
							"\tcenter(5.00, 10.00)\n"
							"\tradius = 12.00\n";

				CHECK(circle.ToString() == str1);
			}
		}
	}
}