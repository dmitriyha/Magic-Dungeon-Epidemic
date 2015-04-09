#include "Game.h"


Game::Game()
{
	initialize();
}

void Game::run(){
	//PlaySound("music\\game1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC | SND_NOSTOP);
	if (win.windowExists()){
		setlocale(LC_ALL, "finnish"); //Voi printata ääkkösiä
		camData->leftCorner = win.getUpperCorner();
		while (quit == false){
			MouseCoordinates mouseClick{ -1, -1, NONE };
			while (SDL_PollEvent(&event)){
				switch (event.type){
					break;
					case SDL_KEYDOWN:
						managePlayer.eventHandler(event,turn);
						//Cooldownchecks
						managebuilding.BuildingCooldownCheck();
						managebuilding.TrapAttackEnemys(camData, attackCooldownStruct);
						managebuilding.TrapAttackCooldownCheck(attackCooldownStruct);
						managePlayer.RangedCombatAttackCooldownCheck();
						break; 
					case SDL_MOUSEBUTTONDOWN:
						//Players actionmanager, that manages players actions
						managebuilding=managePlayer.PlayerActionManager(event, camData, mapdata, managebuilding, ui);
						break;
					case SDL_QUIT:
						quit = true;
						break;
				}//end switch (event.type)

			}//end while(SDL_PollEvent( &event ))
			if (managePlayer.playerMoved){
				manageEnemy.move(attackCooldownStruct);
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
	enemyTexture->makeTexture("img\\BODY_male.png");

	Texture* itemTexture = new Texture();
	itemTexture->setRenderer(win.getRenderer());
	itemTexture->makeTexture("img\\items.png");

	renderItem.setPointer(camData);

	EnemyGen b(camData, enemyTexture);
	PlaceItemsAndEnemies c(camData, itemTexture,map);

	map->setRenderer(win.getRenderer());

	mapTexture = map->getMapAsTexture();
	win.setCanvasSize(mapTexture);

	Texture* texture = new Texture();
	texture->setRenderer(win.getRenderer());

	texture->makeTexture("img\\BODY_male.png");
	Player* player = new Player();
	player->setTexture(texture);

	managePlayer.setPointers(camData);
	managePlayer.setPlayerPointer(player);
	managePlayer.SetRangedCombatCooldown(0);

	manageEnemy.setPointers(camData);
	manageEnemy.setPlayerPointer(player);

	//Initialize building texture
	Texture* building = new Texture();
	building->setRenderer(win.getRenderer());
	building->makeTexture("img\\Building.png");
	managebuilding.initializeBuildings(camData, building, player);

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
