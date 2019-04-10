#include "pch.h"
#include "IShape.h"
#include "CShape.h"

CShape::CShape()
{
}

CShape::~CShape()
{
}

double CShape::GetArea() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

double CShape::GetPerimeter() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

std::string CShape::ToString()
{
	// TODO: Add your implementation code here.
	return std::string();
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}
