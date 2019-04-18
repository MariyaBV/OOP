#include "pch.h"
#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

CCircle::CCircle(CPoint const& center, double const& radius, string& outlineColor, string& fillColor)
	: m_center(center)
	, m_radius(radius)
	, CSolidShape("Circle", outlineColor, fillColor)
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

double CCircle::GetRadius() const
{
	return m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

void CCircle::AppendProperties2(ostream& strm) const
{
	strm << fixed << setprecision(2)
		 << "\tcenter(" << m_center.x << ", " << m_center.y << ")" << endl
		 << "\tradius = " << GetRadius() << endl;
}
