#pragma once
#include <SDL.h>
#include "Object.h"

class Button : public Object
{
public:
	Button();
	void setLocation(int x, int y);
	bool isPressed(SDL_Event event);
	~Button();
};

