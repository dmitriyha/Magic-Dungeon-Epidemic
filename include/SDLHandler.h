#ifndef SDLHANDLER_H
#define SDLHANDLER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include <SDL2/SDL_ttf.h>
#include "GlobalDef.h"
#include "ReadFile.h"
using namespace std;

class SDLHandler{
	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Rect camera={0,0,WINDOW_WIDTH,WINDOW_HEIGHT};
public: 
	SDLHandler();
	SDL_Surface* getScreen();
	void update(void);
	~SDLHandler();
};
#endif
