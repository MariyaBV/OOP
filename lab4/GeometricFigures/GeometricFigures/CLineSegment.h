#pragma once
#include "CShape.h"
#include "CPoint.h"

class CLineSegment : public CShape
{
public:
	CLineSegment();
	~CLineSegment();

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() override;
	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
};
