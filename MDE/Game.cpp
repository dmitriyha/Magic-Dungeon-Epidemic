#include "Game.h"


Game::Game()
{
	camData->currentLevel = 0;
	map= new Map(camData);
	EnemyGen b(camData);
	PlaceItemsAndEnemies c(camData);

	map->setRenderer(win.getRenderer());

	mapTexture=map->getMapAsTexture();
	win.setCanvasSize(mapTexture);

	Texture* texture = new Texture();
	texture->setRenderer(win.getRenderer());
	texture->makeTexture("img\\player0.png");
	player.setTexture(texture);

}

void Game::run(){
	//PlaySound("music\\game1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC | SND_NOSTOP);
	if (win.windowExists()){
		while (quit == false){
			while (SDL_PollEvent(&event)){
				switch (event.type){
				case SDL_QUIT:
					quit = true;
					break;
				}//end switch (event.type)

				//controls.buttons(event);

			}//end while(SDL_PollEvent( &event ))
			map->render();
			player.render();

			//SDL_RenderCopy(win.getRenderer(), mapTexture->getTexture(), NULL, NULL);

			win.renderFrame();
		}//end while(quit==false)
	}
}

Game::~Game()
{
	delete mapTexture;
	delete camData;
}
