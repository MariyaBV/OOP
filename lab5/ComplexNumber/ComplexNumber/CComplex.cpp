#include "pch.h"
#include "CComplex.h"

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
