#include "pch.h"
#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

CComplex::CComplex(double real, double image)
	: m_real(real)
	, m_image(image)
{
}

CComplex::~CComplex()
{
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

double CComplex::GetMagnitude() const
{
	return sqrt(pow(m_real, 2) + pow(m_image, 2));
}

double CComplex::GetArgument() const
{
	double argument;

	if (m_real == 0)
	{
		throw invalid_argument("Error. Usage: argument from real != 0.\n");
	}
	else if ((m_real > 0) && (m_image >= 0))
	{
		argument = atan(m_image / m_real);
	}
	else if ((m_real > 0) && (m_image < 0))
	{
		argument = 2 * M_PI - atan(fabs(m_image / m_real));
	}
	else if ((m_real < 0) && (m_image >= 0))
	{
		argument = M_PI - atan(fabs(m_image / m_real));
	}
	else if ((m_real < 0) && (m_image < 0))
	{
		argument = M_PI + atan(fabs(m_image / m_real));
	}
	
	return argument;
}

CComplex const operator+(CComplex const& lhs, CComplex const& rhs)
{
	return CComplex(lhs.Re() + rhs.Re(), lhs.Im() + rhs.Im());
}

CComplex const operator-(CComplex const& lhs, CComplex const& rhs)
{
	return CComplex(lhs.Re() - rhs.Re(), lhs.Im() - rhs.Im());
}

CComplex const CComplex::operator + () const
{
	return *this;
}

CComplex const CComplex::operator-() const
{
	return CComplex(-m_real, -m_image);
}

CComplex const operator*(CComplex const& lhs, CComplex const& rhs)
{
	double re = lhs.Re() * rhs.Re() - lhs.Im() * rhs.Im();
	double im = lhs.Im() * rhs.Re() + lhs.Re() * rhs.Im();

	return CComplex(re, im);
}

CComplex const operator/(CComplex const& divisible, CComplex const& divider)
{
	if ((divider.Re() == 0) && (divider.Im() == 0))
	{
		throw invalid_argument("Error: division by zero!\n");
	}

	CComplex div = divider * CComplex(divider.Re(), -divider.Im());
	double doubleDivider = 1 / div.Re();
	CComplex newDivisible = divisible * CComplex(divider.Re(), -divider.Im());

	return CComplex(newDivisible.Re() * doubleDivider, newDivisible.Im() * doubleDivider);
}

CComplex& CComplex::operator+=(CComplex const& rhs)
{
	m_real += rhs.Re();
	m_image += rhs.Im();

	return *this;
}

CComplex& CComplex::operator-=(CComplex const& rhs)
{
	m_real -= rhs.Re();
	m_image -= rhs.Im();

	return *this;
}

CComplex& CComplex::operator*=(CComplex const& rhs)
{
	*this = *this * rhs;

	return *this;
}

CComplex& CComplex::operator/=(CComplex const& rhs)
{
	if ((rhs.Re() == 0) && (rhs.Im() == 0))
	{
		throw invalid_argument("Error: division by zero!\n");
	}

	*this = *this / rhs;

	return *this;
}