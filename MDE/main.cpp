#include "Game.h"
using namespace std;

//sdl event struct
SDL_Event event;

int main(int argc, char* argv[]){
    //freopen( "CON", "wt", stdout );
    
	Game game;
	game.run();
	
	return 0;
}
