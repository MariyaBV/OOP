#include "pch.h"
#include "IShape.h"
#include "CShape.h"
#include "AdditionalFunction.h"

using namespace std;

CShape::CShape(const string& type, string& outlineColor)
	: m_type(type)
	, m_outlineColor(FromStringToUINT32(outlineColor))
{
	//m_outlineColor = FromStringToUINT32(outlineColor);
}

CShape::~CShape()
{
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

//bool CShape::SetOutlineColor(string& outlineColor)
//{
//	if (!outlineColor.empty())
//	{
//		m_outlineColor = FromStringToUINT32(outlineColor);
//
//		return true;
//	}
//
//	return false;
//}

string CShape::ToString() const
{
	ostringstream strm;
	strm << m_type << ":" << endl
		 << setprecision(3)
		 << "\tarea = " << GetArea() << endl
		 << "\tperimeter = " << GetPerimeter() << endl
		 << "\toutline color = " << setfill('0') << setw(6) << hex << GetOutlineColor() << endl;
	AppendProperties(strm);
	return strm.str();
}
