#include "Game.h"


Game::Game()
{
	camData->currentLevel = 0;
	Map a(camData);
	EnemyGen b(camData);
	PlaceItemsAndEnemies c(camData);

	mapTexture=a.getMapAsTexture(win.getRenderer());
}

void Game::run(){
	PlaySound("music\\game1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC | SND_NOSTOP);
	while (quit == false){
		while (SDL_PollEvent(&event)){
			switch (event.type){
			case SDL_QUIT:
				quit = true;
				break;
			}//end switch (event.type)

			//controls.buttons(event);

			SDL_RenderPresent(win.getRenderer());
		}//end while(SDL_PollEvent( &event ))
	}//end while(quit==false)

	//fclose (stdout);
}

Game::~Game()
{
	delete mapTexture;
	delete camData;
}
