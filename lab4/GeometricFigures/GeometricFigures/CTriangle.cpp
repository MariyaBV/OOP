#include "pch.h"
#include "CTriangle.h"

CTriangle::CTriangle()
{
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetArea() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

double CTriangle::GetPerimeter() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

std::string CTriangle::ToString()
{
	// TODO: Add your implementation code here.
	return std::string();
}

uint32_t CTriangle::GetOutlineColor() const
{
	// TODO: Add your implementation code here.
	return uint32_t();
}

uint32_t CTriangle::GetFillColor() const
{
	// TODO: Add your implementation code here.
	return uint32_t();
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
