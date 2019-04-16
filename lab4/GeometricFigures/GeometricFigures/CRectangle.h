#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CRectangle : public CSolidShape
{
public:
	virtual ~CRectangle();
	CRectangle(CPoint const& leftTop, CPoint const& rightBottom, std::string& outlineColor, std::string & fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	uint32_t GetOutlineColor() const;
	uint32_t GetFillColor() const;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;

	void AppendProperties2(std::ostream& strm) const;
};
