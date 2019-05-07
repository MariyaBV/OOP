#include "pch.h"
#include "CComplex.h"
#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>

using namespace std;

CComplex::CComplex(double real, double image)
	: m_real(real)
	, m_image(image)
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
	
	argument = atan2(m_image, m_real);

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

CComplex const CComplex::operator+() const
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

bool const operator==(CComplex const& lhs, CComplex const& rhs)
{
	bool reAreEqual = (fabs(lhs.Re() - rhs.Re()) < DBL_EPSILON);
	bool imAreEqual = (fabs(lhs.Im() - rhs.Im()) < DBL_EPSILON);

	return (reAreEqual && imAreEqual);
}

bool const operator!=(CComplex const& lhs, CComplex const& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, CComplex const& complexNumber)
{
	if ((complexNumber.Im() < 0) && (complexNumber.Re() != 0))
	{
		stream << complexNumber.Re() << complexNumber.Im() << "i";
	}
	else if ((complexNumber.Im() > 0) && (complexNumber.Re() != 0))
	{
		stream << complexNumber.Re() << "+" << complexNumber.Im() << "i";
	}
	else if (complexNumber.Im() == 0)
	{
		stream << complexNumber.Re();
	}
	else if ((complexNumber.Re() == 0) && (complexNumber.Im() != 0))
	{
		stream << complexNumber.Im() << "i";
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, CComplex& complexNumber)
{
	double re = 0;
	double im = 0;

	if ((stream >> re) && (stream >> im) && (stream.get() == 'i'))
	{
		complexNumber = CComplex(re, im);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}

	return stream;
}
