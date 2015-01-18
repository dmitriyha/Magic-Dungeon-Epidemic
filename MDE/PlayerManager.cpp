#include "PlayerManager.h"


PlayerManager::PlayerManager()
{

}

void PlayerManager::render(){
	player->render();
}

void PlayerManager::RangedCombatAttackCooldownCheck(AttackCooldownStruct* attackCooldownStruct){
	int i;
	int size = attackCooldownStruct->playerCooldowns.size();
	int cooldown1, cooldown2;
	Player* player = new Player;
	//V‰hennet‰‰n cooldownia
	for (i = 0; i < size; i++){
		player = attackCooldownStruct->playerCooldowns.at(i);
		cooldown1 = player->GetCooldown();
		//V‰hent‰‰ 1 rakennuksen cooldownista
		player->SetCooldown(1);
		cout << "RangedAttackCooldownia on v‰hennetty. Cooldown on " << cooldown1 << endl;
	}
	//tarkistetaan, ett‰ cooldown on suurempi kuin 0
	for (i = 0; i < size; i++){
		player = attackCooldownStruct->playerCooldowns.at(i);
		cooldown2 = player->GetCooldown();
		if (cooldown2 == 0){
			attackCooldownStruct->playerCooldowns.erase(attackCooldownStruct->playerCooldowns.begin() + i);
		}
	}
}

/* \brief gets players coordinates
*   
* \return players coordinates. Save this to example int *coord = . coord[0] is x coordinate, coord[1] is y coordinate.
*/

LocationCoordinates PlayerManager::getPlayerCoord(){
	return player->getCoords();
}

void PlayerManager::eventHandler(SDL_Event event, int& turn ){
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
			turn++;

			cout << turn;
			cout << "\n";
		}

	}
	inventoryData();
	dataForManaging->inventoryStruct.inventory_cursor = inventory_cursor;
}

MouseCoordinates PlayerManager::mouseEventHandler(SDL_Event event){
	LocationCoordinates coord = getPlayerCoord();
	int playerXcoord = coord.x, playerYcoord = coord.y;
	int upperCornerX = 0;
	int upperCornerY = 0;
	switch (event.button.button){

		case SDL_BUTTON_LEFT:
			//if (event.button.button == SDL_BUTTON_LEFT){
			SDL_GetMouseState(&mouseCoordX, &mouseCoordY);
			//rangedCombat(mouseCoordX / TILE_WIDTH, mouseCoordY / TILE_HEIGHT);
			cout << "Hiiri " << mouseCoordX << " " << mouseCoordY << endl;
			//}
			return MouseCoordinates{ -1, -1,NONE };
			break;
		case SDL_BUTTON_RIGHT:
			//If left right button is pressed and t is pressed. Then build a tower
			SDL_GetMouseState(&mouseCoordX, &mouseCoordY);
			mouseCoordX = mouseCoordX / TILE_WIDTH;
			mouseCoordY = mouseCoordY / TILE_HEIGHT;

			upperCornerX = player->getCoords().x - CAMERA_GRID_WIDTH / 2;
			upperCornerY = player->getCoords().y - CAMERA_GRID_HEIGHT / 2;

			if (upperCornerX < 0){
				upperCornerX = 0;
			}
			if (upperCornerX + CAMERA_GRID_WIDTH > GRID_WIDTH){
				upperCornerX = GRID_WIDTH - CAMERA_GRID_WIDTH;
			}


			if (upperCornerY < 0){
				upperCornerY = 0;
			}
			if (upperCornerY + CAMERA_GRID_HEIGHT > GRID_HEIGHT){
				upperCornerY = GRID_HEIGHT - CAMERA_GRID_HEIGHT;
			}

			mouseCoordX += upperCornerX;
			mouseCoordY += upperCornerY;

			if (!inventory){

				return MouseCoordinates{ mouseCoordX, mouseCoordY,RIGHT};
			}
			break;
		default:
			return MouseCoordinates{ -1, -1 , NONE};
			break;
	}
}

int PlayerManager::IfThereIsBuilding(CameraStruct* dataForManaging, int currentdepth, int xCoord, int yCoord){

	int buildingID = 0;
	Building* building = new Building();
	if (dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[xCoord][yCoord]>0){
		buildingID = dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[xCoord][yCoord];
		building = dataForManaging->mapStruct[currentdepth].entityDataBuildings.building.at(buildingID - 1);
		if (building->getType() == 0){
			return 0;
		}
		else if (building->getType() == 1){
			return 1;
		}
		else if (building->getType() == 2){
			return 2;
		}
		else{
			return 99;
		}
	}
	else{
		return 99;
	}
}
int PlayerManager::move(int direction){
	LocationCoordinates coord = player->getCoords();
	switch (direction){
		case 2://down

			if (coord.y<GRID_HEIGHT - 1 && 
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1] == 0 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x][coord.y + 1] != '#'&&
				(IfThereIsBuilding(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y+1) <= 0 ||
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y+1]==0
				)){
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.y = coord.y + 1;
				//Collision check
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 1;

			}
			else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1]>0){
				coord.y = coord.y + 1;
				fightAndKillEnemy(coord);
				coord.y = coord.y - 1;
			}
			break;
		case 4://left        
			if (coord.x>0 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x - 1][coord.y] == 0 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x - 1][coord.y] != '#' &&
				(IfThereIsBuilding(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y) <= 0 ||
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x - 1][coord.y] == 0)){

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
			if (coord.x<GRID_WIDTH - 1 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x + 1][coord.y] == 0 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x + 1][coord.y] != '#' &&
				(IfThereIsBuilding(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y) <= 0 ||
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x + 1][coord.y] == 0)){
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
			if (coord.y>0 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y - 1] == 0 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord.x][coord.y - 1] != '#' &&
				(IfThereIsBuilding(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1) <= 0 ||
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y - 1] == 0)){
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
		checkTileForItems();
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

bool PlayerManager::Bresenham(int x1, int y1, int const x2, int const y2, CameraStruct* dataForManaging)
{
	int delta_x(x2 - x1);
	// if x1 == x2, then it does not matter what we set here
	signed char const ix((delta_x > 0) - (delta_x < 0));
	delta_x = std::abs(delta_x) << 1;

	int delta_y(y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = std::abs(delta_y) << 1;

	cout << "X on " << x1 << ", Y on " << y1 << endl;
	//plot(x1, y1);

	if (delta_x >= delta_y)
	{
		// error may go below zero
		int error(delta_y - (delta_x >> 1));

		while (x1 != x2)
		{
			if ((error >= 0) && (error || (ix > 0)))
			{
				error -= delta_x;
				y1 += iy;
			}
			// else do nothing

			error += delta_y;
			x1 += ix;
			if (CheckTile(x1, y1, dataForManaging) == false){
				return false;
			}
			//cout << "X on " << x1 << ", Y on " << y1 << endl;
			//plot(x1, y1);
		}
	}
	else
	{
		// error may go below zero
		int error(delta_x - (delta_y >> 1));

		while (y1 != y2)
		{
			if ((error >= 0) && (error || (iy > 0)))
			{
				error -= delta_y;
				x1 += ix;
			}
			// else do nothing

			error += delta_x;
			y1 += iy;

			if (CheckTile(x1, y1, dataForManaging) == false){
				return false;
			}
			//cout << "X on " << x1 << ", Y on " << y1 << endl;
			//plot(x1, y1);
		}
	}
	return true;
}

bool PlayerManager::CheckTile(int x, int y, CameraStruct* dataForManaging){
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[x][y] != '#'){
		return true;
	}
	else{
		return false;
	}
}

/** \brief SetRangedCombatCooldown: Sets cooldown for a players ranged combat.
*
* \param int cooldown: the cooldown you want to set for the players ranged combat
*
*/
void PlayerManager::SetRangedCombatCooldown(int cooldown){
	rangedCombatCooldown = cooldown;
	player->SetCooldown(cooldown);
}
/** \brief GettowerCooldown: Gets building cooldown
*
* \param string building: name of the building which cooldown you want to check
* \return true if cooldown is zero. Return false is cooldown is not yet ended.
*
*/
bool PlayerManager::GetRangedCombatCooldown(){

	if (rangedCombatCooldown > 0){
		return false;
	}
	else{
		return true;
	}

}



bool PlayerManager::InRangeOfRangedWeaponCheck(int destinationX, int destinationY, int range, CameraStruct* camData, MapData mapdata){
	int rangeX=0, rangeY=0;
	//if playerIsHere is true, then player is in the selected tile.
	bool playerIsHere = false;

	//if inRange is true, then inRange is in allowed range.
	bool inRange = false;

	//if enemyIsHere is true, then enemy is in the selected tile.
	bool enemyIsHere = false;

	//If buildingIsHere is true, then building is already in the selected tile
	bool buildingIsHere = false;

	//If wallIsHere is true, then wall is already in the selected tile
	bool wallIsHere = false;

	//If player is in the selected tile
	if (player->getCoords().x == destinationX && player->getCoords().y == destinationY){
		playerIsHere = true;
	}
	
		//Range X
		rangeX = player->getCoords().x - destinationX;
		//Range Y
		rangeY = player->getCoords().y - destinationY;
	
		//If range is 0 or less then range default is 5
		if (range <= 0){
			if (rangeX >= -5 && rangeX <= 5 && rangeY >= -5 && rangeY <= 5){
				inRange = true;
			}
			else{
				cout << "You selected a tile out of your weapon range" <<endl;
			}
		}
		else{
			if (rangeX >= -range && rangeX <= range && rangeY >= -range && rangeY <= range){
				inRange = true;
			}
		}

	if (camData->mapStruct[camData->currentLevel].entityData.live[destinationX][destinationY] > 0){
		enemyIsHere = true;
	}
	if (mapdata.buildingDataMap[destinationX][destinationY] != 0){
		buildingIsHere = true;
	}
	//if (camData->mapStruct[dataForManaging->currentLevel].mapData.buildingDataMap[destinationX][destinationY] != 0){ //ei ole alustettu
	//	buildingIsHere = true;
	//}
	if (camData->mapStruct[camData->currentLevel].mapData.mapDim[destinationX][destinationY] == '#'){
		wallIsHere = true;
	}
	///Final check. If values are desirable, then we can shoot
	if (playerIsHere == false &&
		inRange == true &&
		buildingIsHere == false &&
		wallIsHere == false &&
		enemyIsHere == true){

		return true;
	}
	//if values are not desirable, then we will not shoot anything
	else{
		return false;
	}
}

bool PlayerManager::CheckIfThereIsObstaclesInRangedCombat(int x1, int y1, int const x2, int const y2, CameraStruct* dataForManaging)
{
	int delta_x(x2 - x1);
	// if x1 == x2, then it does not matter what we set here
	signed char const ix((delta_x > 0) - (delta_x < 0));
	delta_x = std::abs(delta_x) << 1;

	int delta_y(y2 - y1);
	// if y1 == y2, then it does not matter what we set here
	signed char const iy((delta_y > 0) - (delta_y < 0));
	delta_y = std::abs(delta_y) << 1;

	cout << "X on " << x1 << ", Y on " << y1 << endl;
	//plot(x1, y1);

	if (delta_x >= delta_y)
	{
		// error may go below zero
		int error(delta_y - (delta_x >> 1));

		while (x1 != x2)
		{
			if ((error >= 0) && (error || (ix > 0)))
			{
				error -= delta_x;
				y1 += iy;
			}
			// else do nothing

			error += delta_y;
			x1 += ix;
			if (CheckTile(x1, y1, dataForManaging) == false){
				return false;
			}
			//cout << "X on " << x1 << ", Y on " << y1 << endl;
			//plot(x1, y1);
		}
	}
	else
	{
		// error may go below zero
		int error(delta_x - (delta_y >> 1));

		while (y1 != y2)
		{
			if ((error >= 0) && (error || (iy > 0)))
			{
				error -= delta_y;
				x1 += ix;
			}
			// else do nothing

			error += delta_x;
			y1 += iy;

			if (CheckTile(x1, y1, dataForManaging) == false){
				return false;
			}
			//cout << "X on " << x1 << ", Y on " << y1 << endl;
			//plot(x1, y1);
		}
	}
	return true;
}
void PlayerManager::rangedCombat(int coordX, int coordY, CameraStruct* dataForManaging){
	LocationCoordinates coord;
	coord.x = coordX;
	coord.y = coordY;
	if (CheckIfThereIsObstaclesInRangedCombat(getPlayerCoord().x, getPlayerCoord().y, coordX, coordY, dataForManaging) == true){
		cout << "Ranged combat onnistui" << endl;
		fightAndKillEnemy(coord);
		
	}
	else{
		cout << "Este esti taistelun" << endl;
	}
}

void PlayerManager::fightAndKillEnemy(LocationCoordinates coord){//player attack calculation function
	dataForManaging->userInterfaceStruct.playerDamage = BattleHandler::handle(player, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1]));
	cout << "Pelaaja iskee " << dataForManaging->userInterfaceStruct.playerDamage << " damagea" << endl;
	bool enemyAlive = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y]]->Health(dataForManaging->userInterfaceStruct.playerDamage);


	if (!enemyAlive){
		cout << "Vihollinen kuoli " << endl;
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
	dataForManaging->inventoryStruct.inventoryMode = inventory;
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
