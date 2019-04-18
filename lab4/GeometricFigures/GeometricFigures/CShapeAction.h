#pragma once
#include "IShape.h"
#include <boost/noncopyable.hpp>


// Наследование от boost::noncopyable - явный способ запретить копирование и присваивание экземпляров класса
class CShapeAction : boost::noncopyable
{
public:
	CShapeAction(std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	bool Info(std::istream& args);

	void CheckCircleArguments(std::vector<std::string> const& shapeDescription);
	bool AddCircle(std::istream& args);

	void CheckTriangleArguments(const std::vector<std::string>& shapeDescription);
	bool AddTriangle(std::istream& args);

	void CheckRectangleArguments(const std::vector<std::string>& shapeDescription);
	bool AddRectangle(std::istream& args);

	void CheckLineSegmentArguments(const std::vector<std::string>& shapeDescription);
	bool AddLineSegment(std::istream& args);

	std::vector<std::unique_ptr<IShape>> m_shapeList;

private:
	using ActionMap = std::map<std::string, std::function<bool(std::istream& args)>>;
	std::istream& m_input;
	std::ostream& m_output;
	const ActionMap m_actionMap;
};
