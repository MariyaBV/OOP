#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public ISolidShape, public CShape
{
public:
	CSolidShape(std::string const& type, std::string& outlineColor, std::string & fillColor);

	uint32_t GetFillColor() const override;
	std::string ToString() const;
	uint32_t GetOutlineColor() const;

private:
	uint32_t m_fillColor;
	void AppendProperties1(std::ostream& strm) const;
};
