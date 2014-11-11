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
#include "LocationCoordinate.h"
#include "UserInterface.h"

using namespace std;

/** \brief the Graphics engine
 */     


class Window{
	bool success=true;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Rect canvasSize;
	Texture canvas;
	int winWidth = WINDOW_WIDTH;//the initial width of the window
	int winHeight = WINDOW_HEIGHT;//the initial height of the window
	SDL_Rect sceneSize;
	SDL_Rect cameraLocation;

	UserInterface ui;

	public:
		Window( );
		void setCanvasSize(Texture* texture);
		void renderFrame(LocationCoordinates playerLoc);
		void renderWindow();
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		bool windowExists();
		void setCanvas(Texture* _texture);
		void setCanvasAsTarget();
		void setWindowAsTarget();
		void clearScreen();
		~Window();
	protected:
	private:
};

#endif // WINDOW_H
