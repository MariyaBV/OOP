#include "pch.h"
#define _USE_MATH_DEFINES
#include "EquationRoot4.h"
#include <math.h>

using namespace std;

int sgn(double val)
{
	return (val > 0) ? (1) : ((val < 0) ? (-1) : (0));
}

QuadraticRoots Solve2(double a, double b, double c)
{
	QuadraticRoots root;
	double x1, x2;
	double d = pow(b, 2) - 4 * a * c;

	if (d == 0)
	{
		root.root1 = -b / (2 * a);
		root.root2 = root.root1;
		root.rootFound = true;
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);

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

double Solve3(double a, double b, double c, double d) //Vieht Trigonometric Formula
{
	double maxValidSolution;
	double a1 = b / a;
	double b1 = c / a;
	double c1 = d / a;
	double q = (pow(a1, 2) - 3 * b1) / 9;
	double r = (2 * pow(a1, 3) - 9 * a1 * b1 + 27 * c1) / 54;
	double s = pow(q, 3) - pow(r, 2);
	vector<double> roots;

	if (s < 0)
	{
		double x;

		if (q < 0)
		{
			double phi = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			x = -2 * sgn(r) * sqrt(abs(q)) * sinh(phi) - (a1 / 3);
		}
		else if (q > 0)
		{
			double phi = acosh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			x = -2 * sgn(r) * sqrt(abs(q)) * cosh(phi) - (a1 / 3);
		}
		else
		{
			x = -pow((c1 - pow(a1, 3) / 27), 1 / 3) - a1 / 3;
		}
		roots.push_back(x);
	}
	else if (s > 0)
	{
		double phi = acos(r / sqrt(pow(q, 3))) / 3;
		double x1 = -2 * sqrt(q) * cos(phi) - a1 / 3;
		roots.push_back(x1);

		double x2 = -2 * sqrt(q) * cos(phi + 2 * M_PI / 3) - a1 / 3;
		roots.push_back(x2);

		double x3 = -2 * sqrt(q) * cos(phi - 2 * M_PI / 3) - a1 / 3;
		roots.push_back(x3);
	}
	else
	{
		double x1 = -2 * pow(r, 1 / 3) - a1 / 3;
		roots.push_back(x1);

		double x2 = pow(r, 1 / 3) - a1 / 3;
		roots.push_back(x2);
	}

	maxValidSolution = *max_element(roots.begin(), roots.end());

	return maxValidSolution;
}

EquationRoot4 Solve4(double a, double b, double c, double d, double e)
{
	EquationRoot4 root;

	return root;
};
