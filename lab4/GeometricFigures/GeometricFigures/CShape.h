#pragma once
#include "IShape.h"

class CShape : public virtual IShape
{
public:
	CShape(std::string const& type, std::string& outlineColor);

	uint32_t GetOutlineColor() const override;
	std::string ToString() const;

private:
	uint32_t m_outlineColor;
	virtual void AppendProperties(std::ostream& strm) const = 0;
	std::string m_type;
};
