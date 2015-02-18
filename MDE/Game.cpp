#include "Game.h"


Game::Game()
{
	initialize();
}

void Game::run(){
	//PlaySound("music\\game1.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC | SND_NOSTOP);
	if (win.windowExists()){
		setlocale(LC_ALL, "finnish"); //Voi printata ‰‰kkˆsi‰
		camData->leftCorner = win.getUpperCorner();
		while (quit == false){
			MouseCoordinates mouseClick{ -1, -1, NONE };
			while (SDL_PollEvent(&event)){
				switch (event.type){
					break;
					case SDL_KEYDOWN:
						managePlayer.eventHandler(event,turn);
						if (managebuilding.GetBuildingCooldown() == false){
							managebuilding.buildingCooldown--;
							cout << "Rakentamis cooldown on " << managebuilding.buildingCooldown << "\n";
						}

						if (managePlayer.GetRangedCombatCooldown() == false){
							managePlayer.rangedCombatCooldown--;
							cout << "Ranged combat cooldown on " << managePlayer.rangedCombatCooldown << "\n";
						}
						managebuilding.TrapAttackEnemys(camData, attackCooldownStruct);
						TrapAttackCooldownCheck(attackCooldownStruct);
						managePlayer.RangedCombatAttackCooldownCheck(attackCooldownStruct);
						debugPrintAttackCooldowns(attackCooldownStruct);
						break; 
					case SDL_MOUSEBUTTONDOWN:
						
						mouseClick = managePlayer.mouseEventHandler(event);

					/*	cout << "Pelaajan x coordinaatti on " << managePlayer.getPlayerCoord().x << endl;
						cout << "Pelaajan y coordinaatti on " << managePlayer.getPlayerCoord().y << endl;*/
						
						cout << "Hiiren klikkaama x coordinaatti on " << mouseClick.x << endl;
						cout << "Hiiren klikkaama y coordinaatti on " << mouseClick.y << endl;
						/*if (Bresenham(managePlayer.getPlayerCoord().x, managePlayer.getPlayerCoord().y, mouseClick.x, mouseClick.y, camData)==true){
							cout << "Ranged combat palautti true" << endl;
						}*/
						//cout << "P‰‰ ase on " << managePlayer.getMainWeaponType() << endl;
						if (managePlayer.GetRangedCombatCooldown() == true && managePlayer.getMainWeaponType() == "bow"){
							if (managePlayer.InRangeOfRangedWeaponCheck(mouseClick.x, mouseClick.y, 0, camData, mapdata) == true){
								cout << "Aloitetaan ranged combat check" << endl;
								managePlayer.rangedCombat(mouseClick.x, mouseClick.y,camData);
								managePlayer.SetRangedCombatCooldown(4);
								
							}
							else{
								cout << "Ei ole mit‰‰n hyˆk‰tt‰v‰‰" << endl;
							}
						}
						if (mouseClick.button == RIGHT && managebuilding.GetBuildingCooldown()==true){
							
							managebuilding.CreateBuilding(nextBuilding, mouseClick.x, mouseClick.y, 1, ui, event);			
						}
						
						nextBuilding = ui.eventHandler(event);
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


void Game::debugPrintAttackCooldowns(AttackCooldownStruct* attackCooldownStruct){
	int i, cooldown;
	int size = attackCooldownStruct->attackCooldowns.size();
	
	if (size>0){
		Building* building = new Building;
		cout << "Tasta alkaa cooldown lista: ";
		for (i = 0; i < size; i++){
			building = attackCooldownStruct->attackCooldowns.at(i);
			cooldown = building->GetCooldown();
			cout << cooldown << endl;
		}
	}
}


bool Game::CheckTile(int x, int y, CameraStruct* dataForManaging){
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[x][y] != '#'){
		return true;
	}
	else{
		return false;
	}
}

void Game::TrapAttackCooldownCheck(AttackCooldownStruct* attackCooldownStruct){
	int i;
	int size = attackCooldownStruct->attackCooldowns.size();
	int cooldown1, cooldown2;
	Building* building = new Building;
	//V‰hennet‰‰n cooldownia
	for (i = 0; i < size; i++){
		building=attackCooldownStruct->attackCooldowns.at(i);
		cooldown1=building->GetCooldown();
		//V‰hent‰‰ 1 rakennuksen cooldownista
		building->SetCooldown(1);
		cout << "TrapAttackCooldownia on vahennetty. Cooldown on " << cooldown1<<endl;
	}
	//tarkistetaan, ett‰ cooldown on suurempi kuin 0
	for (i = 0; i < size; i++){
		building = attackCooldownStruct->attackCooldowns.at(i);
		cooldown2 = building->GetCooldown();
		if (cooldown2 == 0){
			attackCooldownStruct->attackCooldowns.erase(attackCooldownStruct->attackCooldowns.begin() + i);
		}
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
	PlaceItemsAndEnemies c(camData, itemTexture);

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
