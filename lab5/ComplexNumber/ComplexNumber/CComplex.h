#pragma once
class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	~CComplex();

	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

	CComplex const operator+() const;
	CComplex const operator-() const;



private:
	double m_real;
	double m_image;
};

CComplex const operator+(CComplex const& lhs, CComplex const& rhs);
CComplex const operator-(CComplex const& lhs, CComplex const& rhs);
