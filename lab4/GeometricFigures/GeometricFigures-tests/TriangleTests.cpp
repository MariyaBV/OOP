#include "pch.h"
#include "../GeometricFigures/AdditionalFunction.h"
#include "../GeometricFigures/CTriangle.h"

SCENARIO("Triangle")
{
	GIVEN("2 points and color")
	{
		CPoint vertex1 = { 0.0, 1.0 };
		CPoint vertex2 = { 2.0, 3.0 };
		CPoint vertex3 = { 0.0, 3.0 };

		WHEN("2 points, no color specified")
		{
			std::string outlineColor, fillColor;
			CTriangle triangle1(vertex1, vertex2, vertex3, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(triangle1.GetArea() == 1.50);
			}
			AND_THEN("get perimetr")
			{
				CHECK(triangle1.GetPerimeter() == 6.828);
			}
			AND_THEN("get outline color")
			{
				CHECK(triangle1.GetOutlineColor() == 000000);
			}
			AND_THEN("vertex")
			{
				CHECK(triangle1.GetVertex1().x == 0);
				CHECK(triangle1.GetVertex1().y == 1);

				CHECK(triangle1.GetVertex2().x == 2);
				CHECK(triangle1.GetVertex2().y == 3);

				CHECK(triangle1.GetVertex3().x == 0);
				CHECK(triangle1.GetVertex3().y == 3);
			}
			AND_THEN("information")
			{
				auto str1 = "Triangle:\n"
							"\tarea = 1.50\n"
							"\tperimeter = 6.83\n"
							"\toutline color = 000000\n"
							"\tvertex1(0.00, 1.00)\n"
							"\tvertex2(2.00, 3.00)\n"
							"\tvertex3(0.00, 3.00)\n";

				CHECK(triangle1.ToString() == str1);
			}
		}
	}
}