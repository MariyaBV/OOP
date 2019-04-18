#pragma once
#include "pch.h"

class IShape //абстрактный класс "=0"
{
public:
	virtual ~IShape() = default; //вирт деструктор базового класса обеспечивает вызовы деструкторов всех классов в ожидаемом порядке,
	//а именно, в порядке, обратном вызовам конструкторов соответствующих классов.
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
};
