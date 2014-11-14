#include "Button.h"


Button::Button()
{
	sprite = { 0, 0, 115, 177 };
}

void Button::setLocation(int x, int y){
	SDL_Rect loc=texture->getSize();
	location = { x, y, 64, 96 };
}

Button::~Button()
{
}
