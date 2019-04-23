#include "pch.h"
#include "CSolidShape.h"
#include "AdditionalFunction.h"

using namespace std;

CSolidShape::CSolidShape(string const& type, string& outlineColor, string& fillColor)
	: CShape(type, outlineColor)
	, m_fillColor(FromStringToUINT32(fillColor))
{
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

string CSolidShape::ToString() const
{
	return CShape::ToString();
}

uint32_t CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

void CSolidShape::AppendProperties(ostream& strm) const
{
	strm << "\tfill color = " << setfill('0') << setw(6) << hex << CSolidShape::GetFillColor() << endl;
	AppendSolidShapeChildProperties(strm);
}
