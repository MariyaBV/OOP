#include "pch.h"
#include "CRectangle.h"
#include "CSolidShape.h"

using namespace std;

CRectangle::CRectangle(CPoint const& leftTop, CPoint const& rightBottom, string& outlineColor, string& fillColor)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, CSolidShape("Rectangle", outlineColor, fillColor)
{
}

double CRectangle::GetArea() const
{
	return GetHeight() * GetWidth();
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetHeight() + GetWidth());
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return abs(m_leftTop.y - m_rightBottom.y);
}

double CRectangle::GetHeight() const
{
	return abs(m_leftTop.x - m_rightBottom.x);
}

void CRectangle::AppendSolidShapeChildProperties(ostream& strm) const
{
	strm << fixed << setprecision(2)
		 << "\tleft top(" << m_leftTop.x << ", " << m_leftTop.y << ")" << endl
		 << "\tright bottom(" << m_rightBottom.x << ", " << m_rightBottom.y << ")" << endl
		 << "\twidth = " << GetWidth() << endl
		 << "\theight = " << GetHeight() << endl;
}
