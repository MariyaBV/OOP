#pragma once
#include "pch.h"
#include "IShape.h"

using namespace std;

class CShape : public virtual IShape
{
public:
	CShape(const string& type, string & outlineColor);
	virtual ~CShape();

	uint32_t GetOutlineColor() const override;
	string ToString() const;
	//bool SetOutlineColor(string& outlineColor) override;

private:
	uint32_t m_outlineColor;
	virtual void AppendProperties(ostream& strm) const = 0;
	string m_type;
};
