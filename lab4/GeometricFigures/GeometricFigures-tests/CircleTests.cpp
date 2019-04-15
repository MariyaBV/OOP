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
				cout << "circle   " << circle.GetArea() << endl;
				CHECK(IsEqual(circle.GetArea(), 78.53981));
			}
			AND_THEN("get perimetr")
			{
				cout << "circle  Per  " << circle.GetPerimeter() << endl;
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
}