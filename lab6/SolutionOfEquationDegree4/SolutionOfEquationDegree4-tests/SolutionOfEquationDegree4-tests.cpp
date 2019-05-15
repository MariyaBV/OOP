#include "pch.h"
#include "../SolutionOfEquationDegree4/EquationRoot4.h"

SCENARIO("quadratic solution")
{
	GIVEN("all index")
	{
		QuadraticRoots result, root;

		WHEN("the equation has real roots")
		{
			THEN("different roots")
			{
				result.root1 = -1;
				result.root2 = 2;
				result.rootFound = true;
				root = Solve2(1, -1, -2);
				CHECK(result.root1 == root.root1);
				CHECK(result.root2 == root.root2);
				CHECK(result.rootFound == root.rootFound);
			}
			AND_THEN("equal roots")
			{
				result.root1 = -1;
				result.root2 = -1;
				result.rootFound = true;
				root = Solve2(1, 2, 1);
				CHECK(result.root1 == root.root1);
				CHECK(result.root2 == root.root2);
				CHECK(result.rootFound == root.rootFound);
			}
		}
		AND_WHEN("the equation has not real roots")
		{
			result.root1 = 0;
			result.root2 = 0;
			result.rootFound = false;
			root = Solve2(1, 1, 2);
			CHECK(result.root1 == root.root1);
			CHECK(result.root2 == root.root2);
			CHECK(result.rootFound == root.rootFound);
		}
	}
}

SCENARIO("search for the maximum valid solution")
{
	GIVEN("all index")
	{
		WHEN("the equation has 3 real roots")
		{
			CHECK(Solve3(1, 3, -1, -1) == Approx(0.67513087).epsilon(0.00001)); // x1=-3.21431974, x2=0.67513087, x3=-0.46081113
		}
		AND_WHEN("the equation has 2 real roots")
		{
			CHECK(1 == Solve3(1, 1, -1, -1)); // x1=1 and x2=-1
		}
		AND_WHEN("the equation has 1 real root, Q = (a^2 - 3b)/9")
		{
			THEN("Q > 0")
			{
				CHECK(Solve3(2, 1, -1, -1) == Approx(0.82948).epsilon(0.00001));
			}
			AND_THEN("Q < 0")
			{
				CHECK(Solve3(1, 3, -1, 5) == Approx(-3.64943591).epsilon(0.00001));
			}
			AND_THEN("Q = 0")
			{
				CHECK(Solve3(3, 3, -1, 5) == Approx(-1.74118356).epsilon(0.00001));
			}
		}
	}
}
