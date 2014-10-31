#include "PlayerManager.h"


PlayerManager::PlayerManager()
{

}

void PlayerManager::render(){
	player->render();
}


/* \brief gets players coordinates
*   
* \return players coordinates. Save this to example int *coord = . coord[0] is x coordinate, coord[1] is y coordinate.
*/

LocationCoordinates PlayerManager::getPlayerCoord(){
	return player->getCoords();
}

void PlayerManager::eventHandler(SDL_Event event){
	int direction = 0;
	int size = player->getInventory()->getList().size();


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
				inventory_cursor = dropItem(inventory_cursor);
			}
			break;
		case SDLK_w:
			if (inventory){
				inventory_cursor = equipItem(inventory_cursor);
			}
			break;
		case SDLK_r:
			if (inventory){
				inventory_cursor = remove_secondary_weapon(inventory_cursor);
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
		if (move(direction) || event.key.keysym.sym == SDLK_SPACE){//if player moved...
			playerMoved = true;
		}

	}
	inventoryData();
	dataForManaging->inventoryStruct.inventory_cursor = inventory_cursor;
}

void PlayerManager::mouseEventHandler(SDL_Event event){
	switch (event.button.button){

	case SDL_BUTTON_LEFT:
		//if (event.button.button == SDL_BUTTON_LEFT){
		SDL_GetMouseState(&mouseCoordX, &mouseCoordY);
		rangedCombat(mouseCoordX / TILE_WIDTH, mouseCoordY / TILE_HEIGHT);
		cout << "Hiiri " << mouseCoordX << " " << mouseCoordY << endl;
		//}
		break;
	case SDL_BUTTON_RIGHT:
		//If left mouse button is pressed and t is pressed. Then build a tower

		LocationCoordinates coord = getPlayerCoord();

		int playerXcoord = coord.x, playerYcoord = coord.y;

		SDL_GetMouseState(&mouseCoordX, &mouseCoordY);
		mouseCoordX = mouseCoordX / TILE_WIDTH;
		mouseCoordY = mouseCoordY / TILE_HEIGHT;

		if (!inventory){
			
			buildingManager->CreateBuilding("stonetower", mouseCoordX, mouseCoordY, 1);
		}
		break;
	}
}


int PlayerManager::move(int direction){
	LocationCoordinates coord = player->getCoords();
	switch (direction){
		case 2://down               
			if (coord.y<GRID_HEIGHT - 1 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x][coord.y + 1] != '#'){
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.y = coord.y + 1;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 1;
			}
			else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1]>0){
				coord.y = coord.y + 1;
				fightAndKillEnemy(coord);
				coord.y = coord.y - 1;
			}
			break;
		case 4://left        
			if (coord.x>0 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x - 1][coord.y] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x - 1][coord.y] != '#'){
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.x = coord.x - 1;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 1;
			}
			else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x - 1][coord.y]>0){
				coord.x = coord.x - 1;
				fightAndKillEnemy(coord);
				coord.x = coord.x + 1;
			}
			break;
		case 6: //right
			if (coord.x<GRID_WIDTH - 1 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x + 1][coord.y] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x + 1][coord.y] != '#'){
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.x = coord.x + 1;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 1;
			}
			else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x + 1][coord.y]>0){
				coord.x = coord.x + 1;
				fightAndKillEnemy(coord);
				coord.x = coord.x - 1;
			}
			break;
		case 8://up 
			if (coord.y>0 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y - 1] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x][coord.y - 1] != '#'){
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.y = coord.y - 1;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 1;
			}
			else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y - 1]>0){
				coord.y = coord.y - 1;
				fightAndKillEnemy(coord);
				coord.y = coord.y + 1;
			}
			break;
		default:
			return 0;
			break;
		}//end switch(event.key.keysym.sym)
		checkTileForItems();
		// checks for stariways up or down
		if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x][coord.y] == 'u') {
			dataForManaging->currentLevel++;
			if (dataForManaging->currentLevel > max_achieved_depth){
				max_achieved_depth++;
				//generateMap();
			}
			player->setCoords(dataForManaging->mapStruct[dataForManaging->currentLevel].stairsDown.x, dataForManaging->mapStruct[dataForManaging->currentLevel].stairsDown.y);
		}
		else if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x][coord.y] == 'd'){
			dataForManaging->currentLevel--;
			player->setCoords(dataForManaging->mapStruct[dataForManaging->currentLevel].stairsUp.x, dataForManaging->mapStruct[dataForManaging->currentLevel].stairsUp.y);
		}
		player->setCoords(coord.x, coord.y);
	return 1;
}

void PlayerManager::checkTileForItems(){//checks tile for items and picks up, if inventory not full
	LocationCoordinates coord = player->getCoords();
	while (!dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord.x][coord.y].empty()){
		if (player->getInventory()->storeItem(dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord.x][coord.y].front()) == 1){
			dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord.x][coord.y].pop_front();

		}
		else{
			break;
		}
	}
}

/* \BRIEF RANGED COMBAT
*   may have bugs regarding the damage... investigate later
*/

//TODO fix possible bugs assosiated with this method!!!

void PlayerManager::rangedCombat(int x, int y){
	LocationCoordinates  playerCoordinates = player->getCoords();

	int clickX, clickY;

	clickX = dataForManaging->leftCornerX + x;
	clickY = dataForManaging->leftCornerY + y;

	bool combatHappens = false;

	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[clickX][clickY]>1){
		int distanceX = playerCoordinates.x - clickX;
		int distanceY = playerCoordinates.y - clickY;
		if (distanceX >= -4 && distanceX <= 4 && distanceY == 0){
			while (distanceX != 0){
				if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[playerCoordinates.x - distanceX][playerCoordinates.y] != '#'){
					if (distanceX<0){
						distanceX++;
					}
					else{
						distanceX--;
					}
					combatHappens = true;
				}
				else{
					combatHappens = false;
					cout << "wall encountered" << endl;
					distanceX = 0;
				}
			}
		}
		else if (distanceX == 0 && distanceY <= 4 && distanceY >= -4){
			while (distanceY != 0){
				if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[playerCoordinates.x][playerCoordinates.y - distanceY] != '#'){
					if (distanceY<0){
						distanceY++;
					}
					else{
						distanceY--;
					}
					combatHappens = true;
				}
				else{
					combatHappens = false;
					cout << "wall encountered" << endl;
					distanceY = 0;
				}
			}

		}

		if (combatHappens){
			LocationCoordinates enemyCoord = { 0,0 };
			enemyCoord.x = clickX;
			enemyCoord.y = clickY;
			fightAndKillEnemy(enemyCoord);
		}

	}

	//return true;
}

void PlayerManager::fightAndKillEnemy(LocationCoordinates coord){//player attack calculation function
	dataForManaging->userInterfaceStruct.playerDamage = BattleHandler::handle(player, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1]));
	bool enemyAlive = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y]]->Health(dataForManaging->userInterfaceStruct.playerDamage);


	if (!enemyAlive){
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.dead[coord.x][coord.y] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y];
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
		player->set_xp(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.dead[coord.x][coord.y]]->get_level());
		if (dataForManaging->currentLevel == 2){
			kills++;
		}
	}
}

void PlayerManager::setPlayerPointer(Player* _player){
	player = _player;
	player->set_stats(100,5,5,5,5,5,5,5,5,1);

	RNG random;

	bool placed = false;
	while (!placed){
		int x = random.generate(0, GRID_WIDTH);
		int y = random.generate(0, GRID_HEIGHT);
		if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[x][y] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[x][y] == '.'){
			player->setCoords(x, y);
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[x][y] = 1;
			placed = true;
		}
	}



	dataForManaging->mapStruct[dataForManaging->currentLevel].playerLoc=player->getCoords();
	dataForManaging->userInterfaceStruct.player = player;
	
}



string PlayerManager::getMainWeaponType(){
	return player->getInventory()->equippedList().at(1).getType();
}

int PlayerManager::get_inventory_size(){
	return player->getInventory()->getList().size();
}

void PlayerManager::inventoryData(){
	dataForManaging->inventoryStruct.inventory = player->getInventory()->getList();
	dataForManaging->inventoryStruct.equippedItems = player->getInventory()->equippedList();
}

int PlayerManager::dropItem(int inventory_cursor){
	LocationCoordinates coord = player->getCoords();
	inventory_cursor = player->getInventory()->inventory_control(1, inventory_cursor);
	if (player->getInventory()->dropped_item().getID() != 0){
		dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord.x][coord.y].push_front(player->getInventory()->dropped_item());
	}
	return inventory_cursor;
}

/** \brief Takes the selected item and equips it
*
* \param inventory_cursor the current selection
* \return returns the new cursor number
*
*/


int PlayerManager::equipItem(int inventory_cursor){
	inventory_cursor = player->getInventory()->inventory_control(2, inventory_cursor);
	return inventory_cursor;
}



/** \brief Removes secondary weapon and puts it int the place of the inventory_cursor
*
* \param inventory_cursor the current selection
* \return returns the new cursor number
*
*/


int PlayerManager::remove_secondary_weapon(int inventory_cursor){
	inventory_cursor = player->getInventory()->inventory_control(3, inventory_cursor);
	return inventory_cursor;
}

bool PlayerManager::check_player_death(){
	if (kills == 50){
		return false;
	}
	return player->Health(0);

}



Player* PlayerManager::getPlayer(){
	return player;
}



PlayerManager::~PlayerManager()
{
	delete player;
}
