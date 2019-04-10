#pragma once
#include "IShape.h"

class ISolidShape : public virtual IShape // наследуемся виртуально, чтобы избавиться от ромбовидного наследования
{
public:
	ISolidShape() = default;
	virtual ~ISolidShape() = default;

	virtual uint32_t GetFillColor() const = 0;
};
