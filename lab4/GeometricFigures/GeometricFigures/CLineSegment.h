#pragma once
#include "CShape.h"
#include "CPoint.h"

class CLineSegment final : public CShape
{
public:
	CLineSegment(CPoint const& startPont, CPoint& endPoint, std::string & outlineColor);
	~CLineSegment();

	double GetArea() const override;
	double GetPerimeter() const override;
	uint32_t GetOutlineColor() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	void AppendProperties1(std::ostream& strm) const;
	void AppendProperties2(std::ostream& strm) const override;
};
