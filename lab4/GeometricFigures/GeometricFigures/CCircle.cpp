#include "pch.h"
#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

CCircle::CCircle(CPoint const& center, double const& radius, std::string& outlineColor, std::string & fillColor)
	: m_center(center)
	, m_radius(radius)
	, CSolidShape("Circle", outlineColor, fillColor)
{
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	return (M_PI * pow(m_radius, 2));
}

double CCircle::GetPerimeter() const
{
	return (2 * M_PI * m_radius);
}

uint32_t CCircle::GetOutlineColor() const
{
	return CSolidShape::GetOutlineColor();
}

uint32_t CCircle::GetFillColor() const
{
	return CSolidShape::GetFillColor();
}

double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

void CCircle::AppendProperties2(std::ostream& strm) const
{
	strm << fixed << setprecision(2)
		 << "\tcenter(" << m_center.x << ", " << m_center.y << ")" << endl
		 << "\tradius = " << GetRadius() << endl;
}
