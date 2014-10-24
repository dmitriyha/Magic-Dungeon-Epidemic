#include <iostream>
#include <SDL.h>
#include "Window.h"
#include "Controls.h"
#include "camera.h"
#include "Building.h"
using namespace std;

Building* GetBuilding();

//sdl event struct
SDL_Event event;
Building* building;
Controls controls;

int main(int argc, char* argv[]){
    //freopen( "CON", "wt", stdout );
    
	Window win("Magic Dungeon Epidemic");
	SDL_Renderer * screen=win.getRenderer();
	
	
	Camera camera(controls.getData(),screen);
	camera.renderScreen();
	bool quit=false;
	
	PlaySound("music\\game1.wav",NULL,SND_FILENAME|SND_LOOP|SND_ASYNC|SND_NOSTOP);
	
	while(quit==false){
		while(SDL_PollEvent( &event )){
			switch (event.type){
				case SDL_QUIT:
					quit = true;
					break;
			}//end switch (event.type)

			controls.buttons(event);
			camera.clear_screen();
			building=GetBuilding();
			camera.setBuilding(building);
			camera.renderScreen();
			
			
			

			SDL_RenderPresent( win.getRenderer() );
		}//end while(SDL_PollEvent( &event ))
	}//end while(quit==false)
	
	//fclose (stdout);
	
	return 0;
}

Building*  GetBuilding(){
	building=controls.GetBuilding();
	return building;
}
