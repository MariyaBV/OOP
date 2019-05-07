#pragma once
class CComplex
{
public:
	CComplex(double real = 0, double image = 0);

	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

	CComplex const operator+() const;
	CComplex const operator-() const;

	CComplex& operator+=(CComplex const& rhs);
	CComplex& operator-=(CComplex const& rhs);
	CComplex& operator*=(CComplex const& rhs);
	CComplex& operator/=(CComplex const& rhs);

private:
	double m_real;
	double m_image;
};

CComplex const operator+(CComplex const& lhs, CComplex const& rhs);
CComplex const operator-(CComplex const& lhs, CComplex const& rhs);

CComplex const operator*(CComplex const& lhs, CComplex const& rhs);
CComplex const operator/(CComplex const& divisible, CComplex const& divider);

bool const operator==(CComplex const& lhs, CComplex const& rhs);
bool const operator!=(CComplex const& lhs, CComplex const& rhs);

std::ostream& operator<<(std::ostream& stream, CComplex const& complexNumber);
std::istream& operator>>(std::istream& stream, CComplex& complexNumber);
