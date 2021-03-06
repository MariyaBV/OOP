#include "pch.h"
#include "../SolutionOfEquationDegree4/EquationRoot4.h"

bool CompareVectors(std::vector<double> a, std::vector<double> b)
{
	if (a.size() != b.size())
		return false;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != Approx(b[i]).epsilon(0.0001))
		{
			return false;
		}
	}
	return true;
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
			// x1=-3.21431974, x2=-0.46081113, x3=0.67513087
			std::vector<double> result = { -3.21431974, -0.46081113, 0.67513087 };
			CHECK(CompareVectors(Solve3(1, 3, -1, -1), result));
		}
		AND_WHEN("the equation has 2 real roots")
		{
			//x1=-1 and x2=1
			std::vector<double> result = { -1, 1 };
			CHECK(CompareVectors(Solve3(1, 1, -1, -1), result));
		}
		AND_WHEN("the equation has 1 real root, Q = (a^2 - 3b)/9")
		{
			THEN("Q > 0")
			{
				CHECK(Solve3(2, 1, -1, -1)[0] == Approx(0.82948).epsilon(0.00001));
			}
			AND_THEN("Q < 0")
			{
				CHECK(Solve3(1, 3, -1, 5)[0] == Approx(-3.64943591).epsilon(0.00001));
			}
			AND_THEN("Q = 0")
			{
				CHECK(Solve3(3, 3, -1, 5)[0] == Approx(-1.74118356).epsilon(0.00001));
			}
		}
	}
}

SCENARIO("search all real roots of the equation")
{
	GIVEN("4 degree equation (a = 0)")
	{
		WHEN("a = 0")
		{
			CHECK_THROWS_WITH(Solve4(0, 1, 2, 3, 4), "Error. The zero value of the coefficient A is not allowed\n");
		}
	}

	GIVEN("4 degree equation")
	{
		WHEN("no valid roots")
		{
			CHECK_THROWS_WITH(Solve4(3, 2, 7, 3, 5), "Error. No valid roots.\n");
		}
		AND_WHEN("all valid roots")
		{
			THEN("int roots")
			{
				std::vector<double> result = { -1, 0, 0, 1 };
				CHECK(CompareVectors(Solve4(1, 0, -1, 0, 0).roots, result));
				CHECK(Solve4(1, 0, -1, 0, 0).roots.size() == 4);
			}
			AND_THEN("valid roots")
			{
				std::vector<double> result = { -1.8019377, -0.4450419, 0.5, 1.2469796 };
				CHECK(CompareVectors(Solve4(2, 1, -5, 0, 1).roots, result));
				CHECK(Solve4(2, 1, -5, 0, 1).roots.size() == 4);
			}
		}
		AND_WHEN("two valid roots")
		{
			THEN("int roots")
			{
				std::vector<double> result = { 0,0 };
				CHECK(CompareVectors(Solve4(3, 0, 3, 0, 0).roots, result));
				CHECK(Solve4(3, 0, 3, 0, 0).roots.size() == 2);
			}
			AND_THEN("valid roots")
			{
				std::vector<double> result = { -0.5, 0.715225 };
				CHECK(CompareVectors(Solve4(-2, 1, -5, 1, 2).roots, result));
				CHECK(Solve4(-2, 1, -5, 1, 2).roots.size() == 2);
			}
			AND_THEN("valid root s<0, q>0")
			{
				std::vector<double> result = { 0.407922, 1.343612 };
				CHECK(CompareVectors(Solve4(-4, 3, 3, 1, -1).roots, result));
				CHECK(Solve4(-4, 3, 3, 1, -1).roots.size() == 2);
			}
		}
	}
}
