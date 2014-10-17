#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "GlobalDef.h"
#include "Texture.h"

using namespace std;

/** \brief the Graphics engine
 */     


class Window{
	bool success=false;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	Texture* canvas;
	int winWidth = WINDOW_WIDTH;//the initial width of the window
	int winHeight = WINDOW_HEIGHT;//the initial height of the window
	public:
		Window( );
		void renderFrame();
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		bool windowExists();
		void setCanvas(Texture* _texture);
		~Window();
	protected:
	private:
};

#endif // WINDOW_H
