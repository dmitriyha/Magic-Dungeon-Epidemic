#include "Game.h"


Game::Game()
{
	initialize();
}

void Game::run(){
	//PlaySound("music\\game1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC | SND_NOSTOP);
	if (win.windowExists()){
		camData->leftCorner = win.getUpperCorner();
		while (quit == false){
			MouseCoordinates mouseClick{ -1, -1, NONE };
			while (SDL_PollEvent(&event)){
				switch (event.type){
					case SDL_KEYDOWN:
						managePlayer.eventHandler(event,turn);
						if (managebuilding.GetBuildingCooldown("stonetower") == false){
							managebuilding.stoneTowerCooldown--;
							cout << "Stonetower Cooldown on " << managebuilding.stoneTowerCooldown << "\n";
						}
						break; 
					case SDL_MOUSEBUTTONDOWN:
						mouseClick = managePlayer.mouseEventHandler(event);

						if (mouseClick.button == RIGHT && managebuilding.GetBuildingCooldown("stonetower")==true){
							managebuilding.CreateBuilding("stonetower", mouseClick.x, mouseClick.y, 1);
							managebuilding.SetBuildingCooldown("stonetower");
						}
						break;
					case SDL_QUIT:
						quit = true;
						break;
				}//end switch (event.type)

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
			
			win.setWindowAsTarget();
			//win.clearScreen();
			win.renderFrame(managePlayer.getPlayerCoord());
			ui.render();
			win.renderWindow();
			win.setCanvasAsTarget();

		}//end while(quit==false)
	}
}

void Game::initialize(){
	camData->currentLevel = 0;
	map = new Map(camData);

	Texture* enemyTexture = new Texture();
	enemyTexture->setRenderer(win.getRenderer());
	enemyTexture->makeTexture("img\\goblinsword.png");

	Texture* itemTexture = new Texture();
	itemTexture->setRenderer(win.getRenderer());
	itemTexture->makeTexture("img\\items.png");

	renderItem.setPointer(camData);

	EnemyGen b(camData, enemyTexture);
	PlaceItemsAndEnemies c(camData, itemTexture);

	map->setRenderer(win.getRenderer());

	mapTexture = map->getMapAsTexture();
	win.setCanvasSize(mapTexture);

	Texture* texture = new Texture();
	texture->setRenderer(win.getRenderer());
	texture->makeTexture("img\\player0.png");
	Player* player = new Player();
	player->setTexture(texture);

	managePlayer.setPointers(camData);
	managePlayer.setPlayerPointer(player);

	manageEnemy.setPointers(camData);
	manageEnemy.setPlayerPointer(player);

	//Initialize building texture
	Texture* stonetower = new Texture();
	stonetower->setRenderer(win.getRenderer());
	stonetower->makeTexture("img\\TowerStone.png");
	managebuilding.initializeBuildings(camData, stonetower, player);


	Texture* uiTexture = new Texture();
	uiTexture->setRenderer(win.getRenderer());
	uiTexture->makeTexture("img\\userinterface.png");

	ui.initialize(camData, uiTexture,itemTexture);
}

Game::~Game()
{
	delete mapTexture;
	delete camData;
}
