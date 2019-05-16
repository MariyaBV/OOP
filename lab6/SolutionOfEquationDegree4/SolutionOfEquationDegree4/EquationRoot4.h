#pragma once

struct QuadraticRoots
{
	bool rootFound = false;
	double root1 = 0;
	double root2 = 0;
};

struct EquationRoot4
{
	std::vector<double> roots;
};

int sgn(double val);
bool IsEqual(double a, double b);
QuadraticRoots Solve2(double a, double b, double c);
std::vector<double> Solve3(double a, double b, double c, double d);
EquationRoot4 Solve4(double a, double b, double c, double d, double e);
EquationRoot4 AddAllRoots(QuadraticRoots const& rootsOfFirstSolve, QuadraticRoots const& rootsOfSecondSolve);
