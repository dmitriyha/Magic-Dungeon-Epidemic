#include "Window.h"

Window::Window(string windowName){
	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		cout<<"SDL could not initialize! SDL Error: "<< SDL_GetError()<<endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			cout<<"Warning: Linear texture filtering not enabled!"<<endl;
		}

		//Create window
		window = SDL_CreateWindow( windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			cout<<"Window could not be created! SDL Error: "<< SDL_GetError() <<endl;
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer == NULL )
			{
				cout<<"Renderer could not be created! SDL Error: "<< SDL_GetError() <<endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					cout<<"SDL_image could not initialize! SDL_image Error: "<< IMG_GetError() <<endl;
					success = false;
				}
			}
		}
	}
	if( TTF_Init() == -1 ) { }
}

SDL_Renderer* Window::getRenderer(){
	return renderer;
}

Window::~Window(){
	//Destroy window	
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
