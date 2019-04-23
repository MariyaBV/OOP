#include "pch.h"
#include "CShapeAction.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CShapeAction::CShapeAction(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({ { "Circle", bind(&CShapeAction::AddCircle, this, placeholders::_1) },
		  { "Triangle", bind(&CShapeAction::AddTriangle, this, placeholders::_1) },
		  { "Rectangle", bind(&CShapeAction::AddRectangle, this, placeholders::_1) },
		  { "LineSegment", bind(&CShapeAction::AddLineSegment, this, placeholders::_1) } })
{
}

bool CShapeAction::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

void CShapeAction::PrintShapeWithMaxArea()
{
	if (!m_shapeList.empty())
	{
		auto shapeMaxArea = max_element(m_shapeList.begin(), m_shapeList.end(), [](const auto& arg1, const auto& arg2) {
			return arg1->GetArea() < arg2->GetArea();
		});

		m_output << "Maximum area shape: " << (*shapeMaxArea)->ToString() << endl;
	}
}

void CShapeAction::PrintShapeWithMinPerimeter()
{
	if (!m_shapeList.empty())
	{
		auto shapeMinPerimeter = min_element(m_shapeList.cbegin(), m_shapeList.cend(), [](const auto& arg1, const auto& arg2) {
			return arg1->GetPerimeter() < arg2->GetPerimeter();
		});

		m_output << "Minimum perimeter shape: " << (*shapeMinPerimeter)->ToString() << endl;
	}
}

void CShapeAction::Info()
{
	for (const auto& shape : m_shapeList)
	{
		cout << shape->ToString() << endl;
	}
}

bool CShapeAction::AddCircle(istream& args)
{
	vector<string> shapeDescription;
	string description;
	getline(args, description);
	if (!description.empty())
	{
		boost::split(shapeDescription, description, boost::is_any_of(" "));
	}

	if (shapeDescription.size() != 4 && shapeDescription.size() != 6)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: Circle center.x center.y radius { outline fill }\n");
	}

	CPoint center = { stod(shapeDescription[1]), stod(shapeDescription[2]) };
	double radius = stod(shapeDescription[3]);
	string outlineColor = "000000";
	string fillColor = "ffffff";

	if (shapeDescription.size() == 6)
	{
		outlineColor = shapeDescription[4];
		fillColor = shapeDescription[5];
	}

	auto circle = make_unique<CCircle>(center, radius, outlineColor, fillColor);
	m_shapeList.push_back(std::move(circle));

	return true;
};

bool CShapeAction::AddTriangle(istream& args)
{
	vector<string> shapeDescription;
	string description;
	getline(args, description);
	if (!description.empty())
	{
		boost::split(shapeDescription, description, boost::is_any_of(" "));
	}

	if (shapeDescription.size() != 7 && shapeDescription.size() != 9)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex.3y {outline fill}\n");
	}

	CPoint vertex1 = { stod(shapeDescription[1]), stod(shapeDescription[2]) };
	CPoint vertex2 = { stod(shapeDescription[3]), stod(shapeDescription[4]) };
	CPoint vertex3 = { stod(shapeDescription[5]), stod(shapeDescription[6]) };
	string outlineColor = "000000";
	string fillColor = "ffffff";

	if (shapeDescription.size() == 9)
	{
		outlineColor = shapeDescription[7];
		fillColor = shapeDescription[8];
	}

	auto triangle = make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
	m_shapeList.push_back(std::move(triangle));

	return true;
};

bool CShapeAction::AddRectangle(istream& args)
{
	vector<string> shapeDescription;
	string description;
	getline(args, description);
	if (!description.empty())
	{
		boost::split(shapeDescription, description, boost::is_any_of(" "));
	}

	if (shapeDescription.size() != 5 && shapeDescription.size() != 7)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: Rectangle leftTop.x leftTop.y rightBottom.x rightBottom.y {outline fill}\n");
	}

	CPoint leftTop = { stod(shapeDescription[1]), stod(shapeDescription[2]) };
	CPoint rightBottom = { stod(shapeDescription[3]), stod(shapeDescription[4]) };
	string outlineColor = "000000";
	string fillColor = "ffffff";

	if (shapeDescription.size() == 7)
	{
		outlineColor = shapeDescription[5];
		fillColor = shapeDescription[6];
	}

	auto rectangle = make_unique<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
	m_shapeList.push_back(std::move(rectangle));

	return true;
};

bool CShapeAction::AddLineSegment(istream& args)
{
	vector<string> shapeDescription;
	string description;
	getline(args, description);
	if (!description.empty())
	{
		boost::split(shapeDescription, description, boost::is_any_of(" "));
	}

	if (shapeDescription.size() != 5 && shapeDescription.size() != 6)
	{
		throw invalid_argument("Incorrect count of arguments!\nUsage: LineSegment vertex1.x vertex1.y vertex2.x vertex2.y {outline}\n");
	}

	CPoint vertex1 = { stod(shapeDescription[1]), stod(shapeDescription[2]) };
	CPoint vertex2 = { stod(shapeDescription[3]), stod(shapeDescription[4]) };
	string outlineColor = "000000";

	if (shapeDescription.size() == 6)
	{
		outlineColor = shapeDescription[5];
	}

	auto lineSegment = make_unique<CLineSegment>(vertex1, vertex2, outlineColor);
	m_shapeList.push_back(std::move(lineSegment));

	return true;
};
