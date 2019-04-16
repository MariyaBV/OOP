#include "pch.h"
#include "CTriangle.h"
#include "CSolidShape.h"

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string& outlineColor, std::string& fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape("Triangle", outlineColor, fillColor)
{
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetArea() const
{
	return 0.5 * fabs((m_vertex2.x - m_vertex1.x) * (m_vertex3.y - m_vertex1.y) - (m_vertex3.x - m_vertex1.x) * (m_vertex2.y - m_vertex1.y));
}

double CTriangle::GetPerimeter() const
{
	double triangleSide1 = sqrt(pow((m_vertex1.x - m_vertex2.x), 2) + pow((m_vertex1.y - m_vertex2.y), 2));
	double triangleSide2 = sqrt(pow((m_vertex1.x - m_vertex3.x), 2) + pow((m_vertex1.y - m_vertex3.y), 2));
	double triangleSide3 = sqrt(pow((m_vertex2.x - m_vertex3.x), 2) + pow((m_vertex2.y - m_vertex3.y), 2));

	return (triangleSide1 + triangleSide2 + triangleSide3);
}

uint32_t CTriangle::GetOutlineColor() const
{
	return CSolidShape::GetOutlineColor();
}

uint32_t CTriangle::GetFillColor() const
{
	return CSolidShape::GetFillColor();
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::AppendProperties2(std::ostream& strm) const
{
	strm << fixed << setprecision(2) 
		<< "\tvertex1(" << m_vertex1.x << ", " << m_vertex1.y << ")" << endl
		<< "\tvertex2(" << m_vertex2.x << ", " << m_vertex2.y << ")" << endl
		<< "\tvertex3(" << m_vertex3.x << ", " << m_vertex3.y << ")" << endl;
}
