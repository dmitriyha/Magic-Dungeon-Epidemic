#include "Button.h"


Button::Button()
{
	sprite = { 0, 0, 115, 177 };
}

void Button::setLocation(int x, int y){
	SDL_Rect loc=texture->getSize();
	location = { x, y, loc.w/2, loc.h/2 };
}


bool Button::isPressed(SDL_Event event){
	SDL_Rect mouseLoc = { 0, 0, 1, 1 };
	switch (event.button.button){
	case SDL_BUTTON_LEFT:
		SDL_GetMouseState(&mouseLoc.x, &mouseLoc.y);
		if (SDL_HasIntersection(&location, &mouseLoc) == SDL_TRUE){
			cout << "pressed" << endl;
			return true;
		}
		else{
			return false;
		}

		break;
	default:
		return false;
		break;
	}
}

Button::~Button()
{
}
