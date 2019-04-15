#include "pch.h"
#include "../GeometricFigures/AdditionalFunction.h"
#include "../GeometricFigures/CRectangle.h"

SCENARIO("Rectangle")
{
	GIVEN("2 points without color")
	{
		CPoint leftTop = { 2.0, 0.0 };
		CPoint rightBottom = { 0.0, 4.0 };

		WHEN("2 points, no color specified")
		{
			std::string outlineColor, fillColor;
			CRectangle rectangle1(leftTop, rightBottom, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(rectangle1.GetArea() == 8.00);
			}
			AND_THEN("get perimetr")
			{
				CHECK(rectangle1.GetPerimeter() == 12.00);
			}
			AND_THEN("get outline color")
			{
				CHECK(rectangle1.GetOutlineColor() == 000000);
			}
			AND_THEN("get fill color")
			{
				CHECK(rectangle1.GetFillColor() == 000000);
			}
			AND_THEN("vertex, width, height")
			{
				CHECK(rectangle1.GetLeftTop().x == 2);
				CHECK(rectangle1.GetLeftTop().y == 0);

				CHECK(rectangle1.GetRightBottom().x == 0);
				CHECK(rectangle1.GetRightBottom().y == 4);

				CHECK(rectangle1.GetHeight() == 2);
				CHECK(rectangle1.GetWidth() == 4);
			}
			AND_THEN("information")
			{
				auto str1 = "Rectangle:\n"
							"\tarea = 8.00\n"
							"\tperimeter = 12.00\n"
							"\toutline color = 000000\n"
							"\tfill color = 000000\n"
							"\tleft top(2.00, 0.00)\n"
							"\tright bottom(0.00, 4.00)\n"
							"\twidth = 4.00\n"
							"\theight = 2.00\n";

				CHECK(rectangle1.ToString() == str1);
			}
		}
	}
	GIVEN("2 points with color on one segment")
	{
		CPoint leftTop = { 0.0, 0.0 };
		CPoint rightBottom = { 0.0, 4.0 };

		WHEN("2 points, no color specified")
		{
			std::string outlineColor = "7722ff";
			std::string fillColor = "ff5500";
			CRectangle rectangle1(leftTop, rightBottom, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(rectangle1.GetArea() == 0.00);
			}
			AND_THEN("get perimetr")
			{
				CHECK(rectangle1.GetPerimeter() == 8.00);
			}
			AND_THEN("get outline color")
			{
				CHECK(rectangle1.GetOutlineColor() == FromStringToUINT32(outlineColor));
			}
			AND_THEN("get fill color")
			{
				CHECK(rectangle1.GetFillColor() == FromStringToUINT32(fillColor));
			}
			AND_THEN("vertex, width, height")
			{
				CHECK(rectangle1.GetLeftTop().x == 0);
				CHECK(rectangle1.GetLeftTop().y == 0);

				CHECK(rectangle1.GetRightBottom().x == 0);
				CHECK(rectangle1.GetRightBottom().y == 4);

				CHECK(rectangle1.GetHeight() == 0);
				CHECK(rectangle1.GetWidth() == 4);
			}
			AND_THEN("information")
			{
				auto str1 = "Rectangle:\n"
							"\tarea = 0.00\n"
							"\tperimeter = 8.00\n"
							"\toutline color = 7722ff\n"
							"\tfill color = ff5500\n"
							"\tleft top(0.00, 0.00)\n"
							"\tright bottom(0.00, 4.00)\n"
							"\twidth = 4.00\n"
							"\theight = 0.00\n";

				CHECK(rectangle1.ToString() == str1);
			}
		}
	}
}