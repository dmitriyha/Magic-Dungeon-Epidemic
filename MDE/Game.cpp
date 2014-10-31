#include "Game.h"


Game::Game()
{
	camData->currentLevel = 0;
	map= new Map(camData);

	//Enemy Texture
	Texture* enemyTexture = new Texture();
	enemyTexture->setRenderer(win.getRenderer());
	enemyTexture->makeTexture("img\\goblinsword.png");

	Texture* itemTexture=new Texture();
	itemTexture->setRenderer(win.getRenderer());
	itemTexture->makeTexture("img\\items.png");

	renderItem.setPointer(camData);

	EnemyGen b(camData,enemyTexture);
	PlaceItemsAndEnemies c(camData,itemTexture);

	//map Render
	map->setRenderer(win.getRenderer());

	mapTexture=map->getMapAsTexture();
	win.setCanvasSize(mapTexture);

	//Player textures
	Texture* texture = new Texture();
	texture->setRenderer(win.getRenderer());
	texture->makeTexture("img\\player0.png");
	Player* player = new Player();
	player->setTexture(texture);

	//Initialize building texture 
	Texture* stonetower = new Texture();
	stonetower->setRenderer(win.getRenderer());
	stonetower->makeTexture("img\\TowerStone.png");

	managebuilding.initializeBuildings(stonetower);

	//initialize game logic 
	managePlayer.setPointers(camData);
	managePlayer.setPlayerPointer(player);

	manageEnemy.setPointers(camData);
	manageEnemy.setPlayerPointer(player);
}

void Game::run(){
	//PlaySound("music\\game1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC | SND_NOSTOP);
	if (win.windowExists()){
		while (quit == false){
			LocationCoordinates mouseClick{ -1, -1 };
			while (SDL_PollEvent(&event)){
				

				switch (event.type){
					case SDL_KEYDOWN:
						managePlayer.eventHandler(event);
						break; 
					case SDL_MOUSEBUTTONDOWN:
						mouseClick=managePlayer.mouseEventHandler(event);
						if (mouseClick.x > -1){
							managebuilding.CreateBuilding("stonetower", mouseClick.x, mouseClick.y, 1);
						}
						break;
					case SDL_QUIT:
						quit = true;
						break;
				}//end switch (event.type)

				//controls.buttons(event);

			}//end while(SDL_PollEvent( &event ))
			if (managePlayer.playerMoved){
				manageEnemy.move(0);
				managePlayer.playerMoved = false;
			}

			map->render();
			renderItem.renderItem(managePlayer.getPlayerCoord());

			manageEnemy.renderEnemy();
			managePlayer.render();

			managebuilding.render();
			

			//SDL_RenderCopy(win.getRenderer(), mapTexture->getTexture(), NULL, NULL);

			win.renderFrame(managePlayer.getPlayerCoord());
		}//end while(quit==false)
	}
}

Game::~Game()
{
	delete mapTexture;
	delete camData;
}
