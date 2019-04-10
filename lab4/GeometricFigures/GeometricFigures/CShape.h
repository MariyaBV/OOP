#pragma once
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape();
	virtual ~CShape();

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() = 0;

	uint32_t GetOutlineColor() const override;

private:
	uint32_t m_outlineColor;
};
