#include "pch.h"
#include "CLineSegment.h"
#include "CShape.h"

using namespace std;

CLineSegment::CLineSegment(CPoint const& startPont, CPoint& endPoint, string& outlineColor)
	: m_startPoint(startPont)
	, m_endPoint(endPoint)
	, CShape("LineSegment", outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return 0.0;
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

void CLineSegment::AppendProperties1(ostream& strm) const
{
	strm << fixed << setprecision(2) << "\tstart point(" << m_startPoint.x << ", " << m_startPoint.y << ")" << endl
		 << "\tend point(" << m_endPoint.x << ", " << m_endPoint.y << ")" << endl;
}

void CLineSegment::AppendProperties2(ostream& strm) const
{
}
