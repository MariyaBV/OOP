#include "pch.h"
#define _USE_MATH_DEFINES
#include "EquationRoot4.h"
#include <math.h>

using namespace std;

bool IsEqual(double a, double b)
{
	double eps = 0.0000001;

	return abs(a - b) < eps;
}

int sgn(double val)
{
	return (val > 0) ? (1) : ((val < 0) ? (-1) : (0));
}

EquationRoot4 AddAllRoots(QuadraticRoots const& rootsOfFirstSolve, QuadraticRoots const& rootsOfSecondSolve)
{
	EquationRoot4 roots;

	if (rootsOfFirstSolve.rootFound)
	{
		roots.roots.push_back(rootsOfFirstSolve.root1);
		roots.numRoots++;
		roots.roots.push_back(rootsOfFirstSolve.root2);
		roots.numRoots++;

		if (rootsOfSecondSolve.rootFound)
		{
			roots.roots.push_back(rootsOfSecondSolve.root1);
			roots.numRoots++;
			roots.roots.push_back(rootsOfSecondSolve.root2);
			roots.numRoots++;
		}
	}
	else
	{
		if (rootsOfSecondSolve.rootFound)
		{
			roots.roots.push_back(rootsOfSecondSolve.root1);
			roots.numRoots++;
			roots.roots.push_back(rootsOfSecondSolve.root2);
			roots.numRoots++;
		}
	}

	sort(roots.roots.begin(), roots.roots.end());
	return roots;
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

vector<double> Solve3(double a, double b, double c, double d) //Vieht Trigonometric Formula
{
	double a1 = b / a;
	double b1 = c / a;
	double c1 = d / a;
	double q = (pow(a1, 2) - 3 * b1) / 9;
	double r = (2 * pow(a1, 3) - 9 * a1 * b1 + 27 * c1) / 54;
	double s = pow(q, 3) - pow(r, 2);
	vector<double> roots;

	if (IsEqual(s, 0))
	{
		double x1 = -2 * sgn(r) * sqrt(q) - a1 / 3;
		roots.push_back(x1);

		double x2 = sgn(r) * sqrt(q) - a1 / 3;
		roots.push_back(x2);
	}
	else if (s < 0)
	{
		double x;

		if (IsEqual(q, 0))
		{
			x = -pow((c1 - pow(a1, 3) / 27), 1 / 3) - a1 / 3;
		}
		else if (q < 0)
		{
			double phi = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			x = -2 * sgn(r) * sqrt(abs(q)) * sinh(phi) - (a1 / 3);
		}
		else if (q > 0)
		{
			double phi = acosh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			x = -2 * sgn(r) * sqrt(abs(q)) * cosh(phi) - (a1 / 3);
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

	sort(roots.begin(), roots.end());
	return roots;
}

EquationRoot4 Solve4(double a, double b, double c, double d, double e) // Ferrari method
{
	EquationRoot4 roots;

	if (a == 0)
	{
		throw invalid_argument("Error. The zero value of the coefficient A is not allowed\n");
	}

	double a3 = b / a;
	double a2 = c / a;
	double a1 = d / a;
	double a0 = e / a;

	vector<double> u = Solve3(1, -a2, (a1 * a3 - 4 * a0), -(pow(a1, 2) + a0 * pow(a3, 2) - 4 * a0 * a2));

	double p0 = pow(a3, 2) / 4 + u[0] - a2;
	double q0 = pow(u[0], 2) / 4 - a0;
	double necessaryU = u[0];

	if ((p0 < 0 || q0 < 0) && (u.size() > 1))
	{
		p0 = pow(a3, 2) / 4 + u[1] - a2;
		q0 = pow(u[1], 2) / 4 - a0;
		necessaryU = u[1];

		if ((p0 < 0 || q0 < 0) && (u.size() > 2))
		{
			p0 = pow(a3, 2) / 4 + u[2] - a2;
			q0 = pow(u[2], 2) / 4 - a0;
			necessaryU = u[2];
		}
	}

	if (p0 >= 0 && q0 >= 0)
	{
		double p1 = a3 / 2 + sqrt(p0);
		double p2 = a3 / 2 - sqrt(p0);
		double q1 = necessaryU / 2 + sqrt(q0);
		double q2 = necessaryU / 2 - sqrt(q0);
		QuadraticRoots rootsOfFirstSolve;
		QuadraticRoots rootsOfSecondSolve;

		if (!IsEqual((p1 * q2 + p2 * q1), a3))
		{
			swap(q1, q2);
		}
		rootsOfFirstSolve = Solve2(1, p1, q1);
		rootsOfSecondSolve = Solve2(1, p2, q2);
		roots = AddAllRoots(rootsOfFirstSolve, rootsOfSecondSolve);

		if (roots.numRoots == 0)
		{
			throw domain_error("Error. No valid roots.\n");
		}
	}
	else
	{
		throw domain_error("Error. No valid roots.\n");
	}

	return roots;
};
