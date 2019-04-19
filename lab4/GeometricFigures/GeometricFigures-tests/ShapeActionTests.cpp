#include "pch.h"
#include "../GeometricFigures/CCircle.h"
#include "../GeometricFigures/CShapeAction.h"

using namespace std;

SCENARIO("check the number of circle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter circle with not all arguments")
		{
			input << "Circle 1.25 3.25";
			CShapeAction rc(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(rc.HandleCommand(), "Incorrect count of arguments!\nUsage: Circle center.x center.y radius { outline fill }\n");
			}
		}
	}
}

SCENARIO("check the number of triangle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter triangle with not all arguments")
		{
			input << "Triangle 8.25 0.25 5 8 10.4";
			CShapeAction rc(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(rc.HandleCommand(), "Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex.3y {outline fill}\n");
			}
		}
	}
}

SCENARIO("check the number of rectangle arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter rectangle with not all arguments")
		{
			input << "Rectangle 8.25 0.25 5.4";
			CShapeAction rc(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(rc.HandleCommand(), "Incorrect count of arguments!\nUsage: Rectangle leftTop.x leftTop.y rightBottom.x rightBottom.y {outline fill}\n");
			}
		}
	}
}

SCENARIO("check the number of line segment arguments")
{
	stringstream input;
	ostringstream output;

	GIVEN("not all arguments")
	{
		WHEN("user enter lineSegment with not all arguments")
		{
			input << "LineSegment 8.25 0.25 5.4";
			CShapeAction rc(input, output);

			THEN("it is notified that not all arguments")
			{
				CHECK_THROWS_WITH(rc.HandleCommand(), "Incorrect count of arguments!\nUsage: LineSegment vertex1.x vertex1.y vertex2.x vertex2.y {outline}\n");
			}
		}
	}
}

SCENARIO("search max area and min perimeter")
{
	stringstream input;
	ostringstream output;

	GIVEN("all shape with true data")
	{
		WHEN("user enter circle, rectangle with arguments without color")
		{
			string inputString = "Rectangle 2.0 0 0 4.0\n"
								 "Circle 0 0 5.0";
			getline(input, inputString);
			CShapeAction rc(input, output);
			rc.HandleCommand();

			//input << "Circle 0 0 5.0";
			//CShapeAction rc(input, output);
			//rc.HandleCommand();

			string result = "Maximum area shape: Circle:\n"
							"\tarea = 78.54\n"
							"\tperimeter = 31.42\n"
							"\toutline color = 000000\n"
							"\tfill color = 000000\n"
							"\tcenter(0.00, 0.00)\n"
							"\tradius = 5.00\n\n"
							"Minimum perimeter shape: Rectangle:\n"
							"\tarea = 8.00\n"
							"\tperimeter = 12.00\n"
							"\toutline color = 000000\n"
							"\tfill color = 000000\n"
							"\tleft top(2.00, 0.00)\n"
							"\tright bottom(0.00, 4.00)\n"
							"\twidth = 4.00\n"
							"\theight = 2.00\n";

			THEN("it is notified that not all arguments")
			{
				rc.PrintShapeWithMaxArea();
				rc.PrintShapeWithMinPerimeter();
				//rc.Info();
				CHECK(output.str() == result);
			}
			AND_THEN("")
			{
			}
		}
	}
}
