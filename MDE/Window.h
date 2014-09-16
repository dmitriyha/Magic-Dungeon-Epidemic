#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "GlobalDef.h"
using namespace std;

/** \brief the Graphics engine
 */     


class Window{
	bool success=false;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	public:
		Window(string );
		SDL_Renderer* getRenderer();
		~Window();
	protected:
	private:
};

#endif // WINDOW_H
