#include "pch.h"
#include "../SolutionOfEquationDegree4/EquationRoot4.h"

bool isEqual(double a, double b)
{
	double eps = 0.0001;

	return abs(a - b) < eps;
}

bool ArrayComparison(int n, double roots1[], double roots2[])
{
	bool equal = true;
	for (size_t i = 0; i < n; ++i)
		if (!isEqual(roots1[i], roots2[i]))
		{
			equal = false;
			break;
		}

	return equal;
}

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

SCENARIO("search all real roots of the equation")
{
	GIVEN("a = 0")
	{
		WHEN("a = 0")
		{
			CHECK_THROWS_WITH(Solve4(0, 1, 2, 3, 4), "Error. The zero value of the coefficient A is not allowed\n");
		}
	}

	GIVEN("all coefficients")
	{
		WHEN("no valid roots")
		{
			CHECK_THROWS_WITH(Solve4(3, 2, 7, 3, 5), "Error. No valid roots.\n");
			CHECK(Solve4(3, 2, 7, 3, 5).numRoots == 0);
		}
		AND_WHEN("all valid roots")
		{
			THEN("int roots")
			{
				EquationRoot4 roots1;
				roots1.roots[-1, 0, 0, 1];

				CHECK(ArrayComparison(4, Solve4(1, 0, -1, 0, 0).roots, roots1.roots));
				CHECK(Solve4(1, 0, -1, 0, 0).numRoots == 4);
			}
			/*AND_THEN("valid roots")
			{
				EquationRoot4 roots;
				roots.roots[-1.8019377, 0.4450419, 0.5, 1.2469796];

				CHECK(ArrayComparison(4, Solve4(2, 1, -5, 0, 1).roots, roots.roots));
				CHECK(Solve4(2, 1, -5, 0, 1).numRoots == 4);
			}*/
		}
		AND_WHEN("two valid roots")
		{
			THEN("int roots")
			{
				EquationRoot4 roots1;
				roots1.roots[0, 0];

				CHECK(ArrayComparison(2, Solve4(3, 0, 3, 0, 0).roots, roots1.roots));
				CHECK(Solve4(3, 0, 3, 0, 0).numRoots == 2);
			}
			/*AND_THEN("valid roots")
			{
				EquationRoot4 roots2;
				roots2.roots[-0.5, 0.7152252];

				CHECK(ArrayComparison(4, Solve4(-2, 1, -5, 1, 2).roots, roots2.roots));
				CHECK(Solve4(-2, 1, -5, 1, 2).numRoots == 2);
			}*/
		}
	}
}
