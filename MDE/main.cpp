#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "Controls.h"
#include "camera.h"
using namespace std;

//sdl event struct
SDL_Event event;

int main(int argc, char* argv[]){
    //freopen( "CON", "wt", stdout );
    
	Window win("Magic Dungeon Epidemic");
	SDL_Renderer * screen=win.getRenderer();
	Controls controls;
	Camera camera(controls.getData(),screen);
	camera.renderScreen();
	bool quit=false;
	
	PlaySound("music\\game1.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC|SND_NOSTOP);
	
	while(quit==false){
		while(SDL_PollEvent( &event )){
			switch (event.type){
				case SDL_KEYDOWN:
					controls.buttons(event);
					camera.clear_screen();
					camera.renderScreen();
					break;//end case SDL_KEYDOWN:
				case SDL_QUIT:
					quit = true;
					break;
			}//end switch (event.type)
			SDL_RenderPresent( win.getRenderer() );
		}//end while(SDL_PollEvent( &event ))
	}//end while(quit==false)
	
	//fclose (stdout);
	
	return 0;
}
