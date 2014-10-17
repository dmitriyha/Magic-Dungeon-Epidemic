#include "Window.h"

/** \brief Sets up the window where the game will be displayed
 *
 * \param windowName The string which will be turned into the name of the window in the top left hand corner of it.
 *
 */     


Window::Window(){
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
		window = SDL_CreateWindow( "Magic Dungeon Epidemic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winWidth, winHeight, SDL_WINDOW_SHOWN );
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
	if (success){
		canvas = new Texture();
		canvas->makeBlankTexture(winWidth,winHeight);
	}
}

void Window::renderFrame(){

}    

SDL_Window* Window::getWindow(){
	return window;//return the pointer to the window object
}

SDL_Renderer* Window::getRenderer(){
	return renderer;//return the pointer to the renderer object
}

bool Window::windowExists(){
	return success;//return the window was created flag
}

/** \brief SDL cleanup.
 * 
 *
 */     


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
