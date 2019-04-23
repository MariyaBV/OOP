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
	CPoint startPoint = GetStartPoint();
	CPoint endPoint = GetEndPoint();
	return sqrt(pow((startPoint.x - endPoint.x), 2) + pow((startPoint.y - endPoint.y), 2));
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

void CLineSegment::AppendProperties(ostream& strm) const
{
	strm << fixed << setprecision(2) << "\tstart point(" << m_startPoint.x << ", " << m_startPoint.y << ")" << endl
		 << "\tend point(" << m_endPoint.x << ", " << m_endPoint.y << ")" << endl;
}
