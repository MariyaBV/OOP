#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint const& center, double const& radius, std::string& outlineColor, std::string& fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	double GetRadius() const;
	CPoint GetCenter() const;

private:
	CPoint m_center;
	double m_radius;

	void AppendProperties2(std::ostream& strm) const;
};
