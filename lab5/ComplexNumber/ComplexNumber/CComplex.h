#pragma once
class CComplex
{
public:
	CComplex(double real, double image);
	~CComplex();

	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

	CComplex const operator+() const;
	CComplex const operator-() const;

private:
	double m_real = 0;
	double m_image = 0;
};

CComplex const operator+(const CComplex& lhs, const CComplex& rhs);
CComplex const operator-(const CComplex& lhs, const CComplex& rhs);
