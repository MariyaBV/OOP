#include "pch.h"
#include "CComplex.h"

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

	if ((m_real == 0) && (m_image == 0))
	{
		throw invalid_argument("Error. Argument zero is undefined.");
	}
	else if ((m_image == 0) && (m_real != 0))
	{
		argument = 0.0;
	}
	else if ((m_real == 0) && (m_image != 0))
	{
		throw invalid_argument("Error. Usage argumet (real != 0).");
	}
	
	return argument;
}
