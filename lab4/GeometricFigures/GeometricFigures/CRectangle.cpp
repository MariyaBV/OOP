#include "pch.h"
#include "CRectangle.h"
#include "CSolidShape.h"

CRectangle::~CRectangle()
{
}

CRectangle::CRectangle(CPoint& leftTop, CPoint& rightBottom, std::string& outlineColor, std::string& fillColor)
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

uint32_t CRectangle::GetOutlineColor() const
{
	return CSolidShape::GetOutlineColor();
}

uint32_t CRectangle::GetFillColor() const
{
	return CSolidShape::GetFillColor();
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

void CRectangle::AppendProperties2(std::ostream& strm) const
{
	strm << fixed << setprecision(2)
		 << "\tleft top(" << m_leftTop.x << ", " << m_leftTop.y << ")" << endl
		 << "\tright bottom(" << m_rightBottom.x << ", " << m_rightBottom.y << ")" << endl
		 << "\twidth = " << GetWidth() << endl
		 << "\theight = " << GetHeight() << endl;
}
