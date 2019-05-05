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

CComplex const operator+(const CComplex& lhs, const CComplex& rhs) 
{
	return CComplex(lhs.Re() + rhs.Re(), lhs.Im() + rhs.Im());
}

CComplex const operator-(const CComplex& lhs, const CComplex& rhs)
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
