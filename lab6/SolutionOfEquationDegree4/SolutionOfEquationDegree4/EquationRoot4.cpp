#include "pch.h"
#include "EquationRoot4.h"

using namespace std;

QuadraticRoots Solve2(double a, double b, double c)
{
	QuadraticRoots root;
	double x1, x2;
	double D = pow(b, 2) - 4 * a * c;

	if (D == 0)
	{
		root.root1 = - b / (2 * a);
		root.root2 = root.root1;
		root.rootFound = true;
	}
	else if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);

		if (x1 < x2)
		{
			root.root1 = x1;
			root.root2 = x2;
		}
		else
		{
			root.root1 = x2;
			root.root2 = x1;
		}
		root.rootFound = true;
	}

	return root;
}

double Solve3(double a, double b, double c, double d)//Vieht Trigonometric Formula
{
	double maxValidSolution = 0;

	return maxValidSolution;
}

//EquationRoot4 Solve4(double a, double b, double c, double d, double e)
//{
//	EquationRoot4 root;
//
//	return root;
//};
