#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CTriangle final : public CSolidShape
{
public:
	CTriangle(CPoint& vertex1, CPoint& vertex2, CPoint& vertex3, std::string& outlineColor, std::string& fillColor);
	~CTriangle();

	double GetArea() const override;
	double GetPerimeter() const override;

	uint32_t GetOutlineColor() const;
	uint32_t GetFillColor() const;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};
