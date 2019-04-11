#include "pch.h"
#include "CTriangle.h"
#include "CSolidShape.h"

CTriangle::CTriangle(CPoint& vertex1, CPoint& vertex2, CPoint& vertex3, std::string& outlineColor, std::string& fillColor)
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
	return 0.0;
}

double CTriangle::GetPerimeter() const
{
	return 0.0;
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
