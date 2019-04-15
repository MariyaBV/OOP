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
			CRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(rectangle.GetArea() == 8.00);
			}
			AND_THEN("get perimetr")
			{
				CHECK(rectangle.GetPerimeter() == 12.00);
			}
			AND_THEN("get outline color")
			{
				CHECK(rectangle.GetOutlineColor() == 000000);
			}
			AND_THEN("get fill color")
			{
				CHECK(rectangle.GetFillColor() == 000000);
			}
			AND_THEN("vertex, width, height")
			{
				CHECK(rectangle.GetLeftTop().x == 2);
				CHECK(rectangle.GetLeftTop().y == 0);

				CHECK(rectangle.GetRightBottom().x == 0);
				CHECK(rectangle.GetRightBottom().y == 4);

				CHECK(rectangle.GetHeight() == 2);
				CHECK(rectangle.GetWidth() == 4);
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

				CHECK(rectangle.ToString() == str1);
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
			CRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);

			THEN("get area")
			{
				CHECK(rectangle.GetArea() == 0.00);
			}
			AND_THEN("get perimetr")
			{
				CHECK(rectangle.GetPerimeter() == 8.00);
			}
			AND_THEN("get outline color")
			{
				CHECK(rectangle.GetOutlineColor() == FromStringToUINT32(outlineColor));
			}
			AND_THEN("get fill color")
			{
				CHECK(rectangle.GetFillColor() == FromStringToUINT32(fillColor));
			}
			AND_THEN("vertex, width, height")
			{
				CHECK(rectangle.GetLeftTop().x == 0);
				CHECK(rectangle.GetLeftTop().y == 0);

				CHECK(rectangle.GetRightBottom().x == 0);
				CHECK(rectangle.GetRightBottom().y == 4);

				CHECK(rectangle.GetHeight() == 0);
				CHECK(rectangle.GetWidth() == 4);
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

				CHECK(rectangle.ToString() == str1);
			}
		}
	}
}