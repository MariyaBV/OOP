#pragma once
#include "IShape.h"
#include <boost/noncopyable.hpp>

// Наследование от boost::noncopyable - явный способ запретить копирование и присваивание экземпляров класса
class CShapeAction : boost::noncopyable
{
public:
	CShapeAction(std::istream& input, std::ostream& output);
	bool HandleCommand();
	void PrintShapeWithMinPerimeter();
	void PrintShapeWithMaxArea();
	void Info();

private:
	bool AddCircle(std::istream& args);
	bool AddTriangle(std::istream& args);
	bool AddRectangle(std::istream& args);
	bool AddLineSegment(std::istream& args);

	std::vector<std::unique_ptr<IShape>> m_shapeList;

private:
	using ActionMap = std::map<std::string, std::function<bool(std::istream& args)>>;
	std::istream& m_input;
	std::ostream& m_output;
	const ActionMap m_actionMap;
};
