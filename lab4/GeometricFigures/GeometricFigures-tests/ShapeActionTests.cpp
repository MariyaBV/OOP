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
	CShapeAction sa(input, output);

	GIVEN("all shape with true data")
	{
		WHEN("user enter circle, rectangle with arguments without color")
		{
			input << "Rectangle 2.0 0 0 4.0\n";
			CShapeAction sa(input, output);
			sa.HandleCommand();
			input << "Circle 0 0 5.0\n";
			sa.HandleCommand();

			string result = "Maximum area shape: Circle:\n"
							"\tarea = 78.54\n"
							"\tperimeter = 31.42\n"
							"\toutline color = 000000\n"
							"\tfill color = ffffff\n"
							"\tcenter(0.00, 0.00)\n"
							"\tradius = 5.00\n\n"
							"Minimum perimeter shape: Rectangle:\n"
							"\tarea = 8.00\n"
							"\tperimeter = 12.00\n"
							"\toutline color = 000000\n"
							"\tfill color = ffffff\n"
							"\tleft top(2.00, 0.00)\n"
							"\tright bottom(0.00, 4.00)\n"
							"\twidth = 4.00\n"
							"\theight = 2.00\n\n";

			THEN("print shape with max area and min perimeter")
			{
				sa.PrintShapeWithMaxArea();
				sa.PrintShapeWithMinPerimeter();
				CHECK(output.str() == result);
			}
		}
		AND_WHEN("user enter Triangle, LineSegment with all arguments")
		{
			input << "Triangle 0 1.0 2.0 3.0 0 3.0 ff0000 00ff99\n";
			CShapeAction sa(input, output);
			sa.HandleCommand();
			input << "LineSegment 0 1.0 2.0 3.0 ff2200\n";
			sa.HandleCommand();

			string result = "Maximum area shape: Triangle:\n"
							"\tarea = 2.00\n"
							"\tperimeter = 6.83\n"
							"\toutline color = ff0000\n"
							"\tfill color = 00ff99\n"
							"\tvertex1(0.00, 1.00)\n"
							"\tvertex2(2.00, 3.00)\n"
							"\tvertex3(0.00, 3.00)\n\n"
							"Minimum perimeter shape: LineSegment:\n"
							"\tarea = 0.00\n"
							"\tperimeter = 2.83\n"
							"\toutline color = ff2200\n"
							"\tstart point(0.00, 1.00)\n"
							"\tend point(2.00, 3.00)\n\n";

			THEN("print shape with max area and min perimeter")
			{
				sa.PrintShapeWithMaxArea();
				sa.PrintShapeWithMinPerimeter();
				CHECK(output.str() == result);
			}
		}
	}
}
