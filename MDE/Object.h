#pragma once

#include "Texture.h"

class Object
{
public:
	Object();
	virtual void render();
	virtual void setTexture(Texture* _texture);
	~Object();
protected:
	Texture* texture; 
	SDL_Rect sprite;
	SDL_Rect location;
};

