#pragma once
#include "ISolidShape.h"
#include "CShape.h"

using namespace std;

class CSolidShape : public ISolidShape, public CShape
{
public:
	CSolidShape(const string& type, string& outlineColor, string& fillColor);
	virtual ~CSolidShape();

	uint32_t GetFillColor() const override;
	string ToString() const;
	uint32_t GetOutlineColor() const;

private:
	uint32_t m_fillColor;
	void AppendProperties1(std::ostream& strm) const;
};
