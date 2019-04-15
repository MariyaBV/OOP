#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint& center, double& radius, std::string& outlineColor, std::string& fillColor);
	virtual ~CCircle();

	double GetArea() const override;
	double GetPerimeter() const override;

	uint32_t GetOutlineColor() const;
	uint32_t GetFillColor() const;

	double GetRadius() const;
	CPoint GetCenter() const;

private:
	CPoint m_center;
	double m_radius;

	void AppendProperties2(std::ostream& strm) const;
};
