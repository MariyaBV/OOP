#include "pch.h"
#include "../GeometricFigures/CShapeAction.h"
#include "../GeometricFigures/CCircle.h"

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