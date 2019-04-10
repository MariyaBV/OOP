#include "pch.h"
#include "CSolidShape.h"


using namespace std;

CSolidShape::CSolidShape()
{
}

CSolidShape::~CSolidShape()
{
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

double CSolidShape::GetArea() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

double CSolidShape::GetPerimeter() const
{
	// TODO: Add your implementation code here.
	return 0.0;
}

std::string CSolidShape::ToString()
{
	// TODO: Add your implementation code here.
	return std::string();
}

uint32_t CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}
