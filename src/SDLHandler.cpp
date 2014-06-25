#include "SDLHandler.h"


SDLHandler::SDLHandler(){//initialises screen
	SDL_Init(SDL_INIT_EVERYTHING);
	window=SDL_CreateWindow( "Magic Dungeon Epidemic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
	screen=SDL_GetWindowSurface( window );
	SDL_Surface* icon = SDL_LoadBMP("img\\icon.bmp");
	//SDL_WM_SetIcon(icon, NULL);
	TTF_Init();
	
}

SDL_Surface* SDLHandler::getScreen(){
	return screen;
}

void SDLHandler::update(){
	SDL_UpdateWindowSurface( window );
}

SDLHandler::~SDLHandler(){
	SDL_FreeSurface( screen );
	screen=NULL;
	SDL_DestroyWindow( window );
	window=NULL;
	SDL_Quit();
}
