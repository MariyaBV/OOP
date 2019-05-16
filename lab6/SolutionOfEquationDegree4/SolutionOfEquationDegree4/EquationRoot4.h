#pragma once

struct QuadraticRoots
{
	bool rootFound = false;
	double root1 = 0;
	double root2 = 0;
};

struct EquationRoot4
{
	size_t numRoots = 0;
	double roots[4];
};

int sgn(double val);
QuadraticRoots Solve2(double a, double b, double c);
double Solve3(double a, double b, double c, double d);
EquationRoot4 Solve4(double a, double b, double c, double d, double e);
