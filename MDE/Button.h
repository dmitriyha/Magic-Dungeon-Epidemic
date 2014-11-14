#pragma once
#include "Object.h"

class Button : public Object
{
public:
	Button();
	void setLocation(int x, int y);
	~Button();
};

