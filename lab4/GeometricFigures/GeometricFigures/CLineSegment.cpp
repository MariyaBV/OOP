#include "pch.h"
#include "CLineSegment.h"
#include "CShape.h"

CLineSegment::CLineSegment(CPoint& startPont, CPoint& endPoint, std::string& outlineColor)
	: m_startPoint(startPont)
	, m_endPoint(endPoint)
	, CShape("LineSegment", outlineColor)
{
}

CLineSegment::~CLineSegment()
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

void CLineSegment::AppendProperties1(std::ostream& strm) const
{
	strm << fixed << setprecision(2) <<
		"\tstart point(" << m_startPoint.x << ", " << m_startPoint.y << ")" << endl
		 << "\tend point(" << m_endPoint.x << ", " << m_endPoint.y << ")" << endl;
}

void CLineSegment::AppendProperties2(std::ostream& strm) const
{
}

