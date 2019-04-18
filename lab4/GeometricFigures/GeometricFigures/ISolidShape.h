#pragma once
#include "IShape.h"

class ISolidShape : public virtual IShape // наследуемся виртуально, чтобы избавиться от ромбовидного наследования
{
public:
	virtual uint32_t GetFillColor() const = 0;
};
