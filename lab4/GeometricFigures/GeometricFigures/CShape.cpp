#include "pch.h"
#include "IShape.h"
#include "CShape.h"
#include "AdditionalFunction.h"

using namespace std;

CShape::CShape(string const& type, string& outlineColor)
	: m_type(type)
	, m_outlineColor(FromStringToUINT32(outlineColor))
{
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

string CShape::ToString() const
{
	ostringstream strm;
	strm << m_type << ":" << endl << fixed << setprecision(2)
		 << "\tarea = " << GetArea() << endl
		 << "\tperimeter = " << GetPerimeter() << endl
		 << "\toutline color = " << setfill('0') << setw(6) << hex << GetOutlineColor() << endl;
	AppendProperties1(strm);
	AppendProperties2(strm);
	return strm.str();
}
