#include "Window.h"

/** \brief Sets up the window where the game will be displayed
 *
 * \param windowName The string which will be turned into the name of the window in the top left hand corner of it.
 *
 */     


Window::Window(){

	sceneSize = { 0, 0, TILE_WIDTH*CAMERA_GRID_WIDTH, TILE_HEIGHT*CAMERA_GRID_HEIGHT };
	cameraLocation = { 0, 0, TILE_WIDTH*CAMERA_GRID_WIDTH, TILE_HEIGHT*CAMERA_GRID_HEIGHT };

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
}

void Window::setCanvasSize(Texture* texture){
	//if window was created, initialise the canvas
	if (success){
		canvasSize = texture->getSize();
		canvas.setRenderer(renderer);
		canvas.makeBlankTexture(canvasSize.w, canvasSize.h);
	}
}


void Window::renderFrame(LocationCoordinates playerLoc){
	
	upperCorner.x = playerLoc.x - CAMERA_GRID_WIDTH / 2;
	upperCorner.y = playerLoc.y - CAMERA_GRID_HEIGHT / 2;

	if (upperCorner.x < 0){
		upperCorner.x = 0;
	}
	if (upperCorner.x + CAMERA_GRID_WIDTH > GRID_WIDTH){
		upperCorner.x = GRID_WIDTH - CAMERA_GRID_WIDTH;
	}


	if (upperCorner.y < 0){
		upperCorner.y = 0;
	}
	if (upperCorner.y + CAMERA_GRID_HEIGHT > GRID_HEIGHT){
		upperCorner.y = GRID_HEIGHT - CAMERA_GRID_HEIGHT;
	}

	

	cameraLocation.x = (upperCorner.x)* TILE_WIDTH;
	cameraLocation.y = (upperCorner.y)* TILE_HEIGHT;

	SDL_RenderCopy(renderer, canvas.getTexture(), &cameraLocation, &sceneSize);

	
}    

void Window::renderWindow(){
	SDL_RenderPresent(renderer); //show the screen
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


void Window::setCanvasAsTarget(){
	SDL_SetRenderTarget(renderer, canvas.getTexture());//set the canvas as the rendering target
}

void Window::setWindowAsTarget(){
	SDL_SetRenderTarget(renderer, NULL); //set the window back as the rendering target
}

void Window::clearScreen(){
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

LocationCoordinates Window::getUpperCorner(){
	return upperCorner;
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
