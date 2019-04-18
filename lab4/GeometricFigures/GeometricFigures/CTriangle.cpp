#include "pch.h"
#include "CTriangle.h"
#include "CSolidShape.h"

using namespace std;

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, string& outlineColor, string& fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape("Triangle", outlineColor, fillColor)
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

void CTriangle::AppendProperties2(ostream& strm) const
{
	strm << fixed << setprecision(2) 
		<< "\tvertex1(" << m_vertex1.x << ", " << m_vertex1.y << ")" << endl
		<< "\tvertex2(" << m_vertex2.x << ", " << m_vertex2.y << ")" << endl
		<< "\tvertex3(" << m_vertex3.x << ", " << m_vertex3.y << ")" << endl;
}
