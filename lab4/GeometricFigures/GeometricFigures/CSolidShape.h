#pragma once
#include "ISolidShape.h"
#include "CShape.h"

using namespace std;

class CSolidShape : public ISolidShape, public CShape
{
public:
	CSolidShape();
	virtual ~CSolidShape();

	uint32_t GetFillColor() const override;
	std::string ToString() override;
	uint32_t GetOutlineColor() const;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;

private:
	uint32_t m_fillColor;
};
