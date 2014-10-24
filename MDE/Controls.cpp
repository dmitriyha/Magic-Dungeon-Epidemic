#include "Controls.h"

/** \brief Constructs a class responsible for all of the controls of the game
 *
 */     


Controls::Controls(){
	cameraData = new CameraStruct;
	cameraData->currentLevel = 0;
	managePlayer = new PlayerManager();
	managePlayer -> setPointers(cameraData);
	managePlayer->setPlayerPointer(new Player());
	//managePlayer->generateMap();
	manageEnemies = new EnemyManager();
	manageEnemies  -> setPointers(cameraData);
	manageEnemies->setPlayerPointer(managePlayer->getPlayer());
	//cameraData=manage->getData();
	
	cameraData->inventoryStruct.inventory_cursor=inventory_cursor;
	cameraData->inventoryStruct.inventoryMode=inventory;
	buildData = &cameraData->buildData;
}

/** \brief the definition of all of the controls
 *
 * \param event the event struct 
 *
 */     

void Controls::buttons(SDL_Event event){
	int direction=0;
	int size = managePlayer->get_inventory_size();
	if (managePlayer->check_player_death()  ){
		if (event.type == SDL_KEYDOWN){
			keyboard(event);
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN){
			mouse(event);
		}
	}
	//manage->getData();
	cameraData->inventoryStruct.inventory_cursor=inventory_cursor;
	cameraData->inventoryStruct.inventoryMode=inventory;
	
}

void Controls::keyboard(SDL_Event event){
	int direction = 0;
	int size = managePlayer->get_inventory_size();
	switch (event.key.keysym.sym){
		case SDLK_i:
			if (!inventory){		//sets inventory to visible
				inventory = true;
			}
			else{				//hides inventory
				inventory = false;
			}
			break;
		case SDLK_d:
			if (inventory){
				inventory_cursor = managePlayer->dropItem(inventory_cursor);
			}
			break;
		case SDLK_w:
			if (inventory){
				inventory_cursor = managePlayer->equipItem(inventory_cursor);
			}
			break;
		case SDLK_r:
			if (inventory){
				inventory_cursor = managePlayer->remove_secondary_weapon(inventory_cursor);
			}

			break;
		case SDLK_DOWN: case SDLK_KP_2:
			if (inventory){
				inventory_cursor = inventory_cursor + 3;
				if (inventory_cursor > size){
					inventory_cursor = size;
				}
			}
			else{
				direction = 2;
			}
			break;
		case SDLK_UP: case SDLK_KP_8:
			if (inventory){
				inventory_cursor = inventory_cursor - 3;
				if (inventory_cursor <= 0){
					inventory_cursor = 1;
				}
			}
			else{
				direction = 8;
			}
			break;
		case SDLK_LEFT: case SDLK_KP_4:
			if (inventory){
				inventory_cursor--;
				if (inventory_cursor <= 0){
					inventory_cursor = 1;
				}
			}
			else{
				direction = 4;
			}
			break;
		case SDLK_RIGHT: case SDLK_KP_6:
			if (inventory){
				inventory_cursor++;
				if (inventory_cursor > size){
					inventory_cursor = size;
				}
			}
			else{
				direction = 6;
			}
			break;
		case SDLK_ESCAPE://also hides inventory when escape is pressed
			if (inventory){
				inventory = false;
			}
			break;
	}//end switch(event.key.keysym.sym)
	if (size == 0){
		inventory_cursor = 1;
	}
	if (!inventory){
		if (managePlayer->move(direction) || event.key.keysym.sym == SDLK_SPACE){//if player moved...
			manageEnemies->move(0);//...move the enemies...
		}

	}
	managePlayer->inventoryData();
	cameraData->inventoryStruct.inventory_cursor = inventory_cursor;
}

void Controls::mouse(SDL_Event event){
	int x, y;
	switch (event.button.button){

	case SDL_BUTTON_LEFT:
	//if (event.button.button == SDL_BUTTON_LEFT){
		SDL_GetMouseState(&x, &y);
		managePlayer->rangedCombat(x / TILE_WIDTH, y / TILE_HEIGHT);
		cout <<"Hiiri " << x << " " << y  << endl;
	//}
	break;
	case SDL_BUTTON_RIGHT:
		//If left mouse button is pressed and t is pressed. Then build a tower
		
		int *coord = managePlayer->getPlayerCoord();

			int playerXcoord = coord[0], playerYcoord = coord[0];
			SDL_GetMouseState(&x, &y);
			x = x / TILE_WIDTH;
			y = y / TILE_HEIGHT;
			/*for (int i = 0; i < 7;i++){

			}*/
			if (!inventory){//&& x == playerXcoord + 1 || x == playerXcoord - 1)
			/*	Building* tower  = BuildingFactory::create_building("stonetower");
				tower->set_stats(1, 1, 1, 1, 1, 1);
				tower->set_level(1);
				tower->setCoords(x, y);
				mapdata.buildingDataMap[x][y] = tower;*/


				buildData->building = BuildingFactory::create_building("stonetower");
				buildData->building->set_stats(1, 1, 1, 1, 1, 1);
				buildData->building->set_level(1);
				buildData->building->setCoords(x, y);
				mapdata.buildingDataMap[x][y] = buildData->building;
				
			}
		break;
	}
}

Building*  Controls::GetBuilding(){

	return buildData->building;

}

/** \brief CameraStruct getter
 *
 */     


CameraStruct* Controls::getData(){
	return cameraData;
}

Controls::~Controls(){
	delete managePlayer;
	delete manageEnemies;
	//delete cameraData;
}
