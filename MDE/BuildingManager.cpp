#include "BuildingManager.h"


BuildingManager::BuildingManager()
{
	
}

/** \brief render: Renders the buildings.
*
*
*/
void BuildingManager::render(){
	for (int i = 0; buildingList.size() > i; i++){
		buildingList.at(i)->render();

	}
}


void BuildingManager::TrapAttackEnemys(CameraStruct* dataForManaging, AttackCooldownStruct* attackCooldownStruct){
	int CoordX, CoordY,j=0,enemyCoordX,enemyCoordY,k=0;
	int numberOfBuildinsTotal = dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.building.size();
	
	for (int j=0; j < numberOfBuildinsTotal; j++){
		try{
			Building* building = new Building();
			building = dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.building.at(j);
		if (building->getType() == 1){
			if (building->Health()>0){
				if (CooldownCheck(attackCooldownStruct, building) == true){
					CoordX = building->getCoords().x;
					CoordY = building->getCoords().y;
					CheckIfThereIsEnemysInRange(CoordX, CoordY, dataForManaging);
					
					if (trapCoord[16] != 0){
						if (building->GetCooldown() == 0){
										building->SetCooldown(-4);
						}
							attackCooldownStruct->attackCooldowns.push_back(building);
				
								for (int i = 0; i < 8; i++){
									if (trapCoord[k] != 0){
										enemyCoordX = trapCoord[k];
										enemyCoordY = trapCoord[k + 1];
										BladeTrapHitsEnemy(dataForManaging, enemyCoordX, enemyCoordY, attackCooldownStruct, building);
									}
									k += 2;


								}					
						}
					}
				}
			}
			}
			catch (exception& e){
				cout << endl << "BuildingsManager heitti " << e.what() << endl;
				cout << "Kaatumisessa rakennusnumero oli " << j << endl;
				cout << "Kaatumisessa rakennuksien maara oli " << numberOfBuildinsTotal << endl;

			}
	}
}


void BuildingManager::BladeTrapHitsEnemy(CameraStruct* dataForManaging, int EnemyCoordX, int EnemyCoordY, AttackCooldownStruct* attackCooldownStruct, Building* building){
	try{
			bool enemyAlive = true;
			dataForManaging->userInterfaceStruct.buildingDamage = building->Damage();
			Enemy* enemy = new Enemy();
			enemy=GetEnemy(dataForManaging, EnemyCoordX, EnemyCoordY);
			enemy->Health(building->Damage());

			if (enemy->Health() <= 0){
				KillEnemy(EnemyCoordX, EnemyCoordY, dataForManaging);
				cout << "Vihollinen kuoli ansaan" << endl;
			}
			cout << "Ansan damage on " << building->Damage() << endl;
	
	}
	catch (exception& e){
		cout << endl << "BuildingsManager heitti " << e.what() << endl;
	}
		
	
}


/** \brief gets enemy at coordinates EnemyCoordX and EnemyCoordY
*
* \param dataForManaging is CameraStruct object
* \param currentdepth is the current depth/level
* \param EnemyCoordX is the enemy coordinate x
* \param EnemyCoordY is the enemy coordinate y
*
* \return enemy object which is at coordinates EnemyCoordX and EnemyCoordY
*/
Enemy* BuildingManager::GetEnemy(CameraStruct* dataForManaging, int EnemyCoordX, int EnemyCoordY){
	int enemyID;
	Enemy* enemy = new Enemy();
	enemyID = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[EnemyCoordX][EnemyCoordY];
	enemy = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(enemyID - 1);
	return enemy;
}

/** \brief Kills the enemy. Removes enemy from the alive array to dead array.
*
* \param coordX is the enemy coordinates x
* \param coordY is the enemy coordinates y
*
* \return True if cooldown is 0. Returns false is cooldown is more than 0.
*/
void BuildingManager::KillEnemy(int coordX, int coordY, CameraStruct *dataForManaging){
	dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.dead[coordX][coordY] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY];
	dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY] = 0;
}

void BuildingManager::CheckIfThereIsEnemysInRange(int trapCoordX, int trapCoordY, CameraStruct *dataForManaging){
	int numberOfBladeTraps = 0;
	memset(trapCoord, 0, sizeof(trapCoord));
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX + 1][trapCoordY]>0){
		trapCoord[0] = (trapCoordX + 1);
		trapCoord[1] = trapCoordY;
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX - 1][trapCoordY]>0){
		trapCoord[2] = (trapCoordX - 1);
		trapCoord[3] = trapCoordY;
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX][trapCoordY + 1]>0){
		trapCoord[4] = trapCoordX;
		trapCoord[5] = (trapCoordY + 1);
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX][trapCoordY - 1]>0){
		trapCoord[6] = trapCoordX;
		trapCoord[7] = (trapCoordY - 1);
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX + 1][trapCoordY + 1]>0){
		trapCoord[8] = (trapCoordX + 1);
		trapCoord[9] = (trapCoordY + 1);
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX + 1][trapCoordY - 1]>0){
		trapCoord[10] = (trapCoordX + 1);
		trapCoord[11] = (trapCoordY - 1);
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX - 1][trapCoordY - 1]>0){
		trapCoord[12] = (trapCoordX - 1);
		trapCoord[13] = (trapCoordY - 1);
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[trapCoordX - 1][trapCoordY + 1]>0){
		trapCoord[14] = (trapCoordX - 1);
		trapCoord[15] = (trapCoordY + 1);
		numberOfBladeTraps++;
		trapCoord[16] = numberOfBladeTraps;
	}


}

/** \brief Checks if trap has a cooldown still
*
* \param attackCooldownStruct handels traps attack cooldown
* \param building which cooldown we want to check
*
* \return True if cooldown is 0. Returns false is cooldown is more than 0.
*/
bool BuildingManager::CooldownCheck(AttackCooldownStruct* attackCooldownStruct, Building* building){
	int i;
	int size = attackCooldownStruct->attackCooldowns.size();
	int cooldown;

	for (i = 0; i < size; i++){
		if (building == attackCooldownStruct->attackCooldowns.at(i)){
			if (building->GetCooldown() > 0){
				return false;
			}
			else{
				return true;
			}
		}
	}
	return true;
}

/** \brief CreateBuilding: Creates a Building.
*
* \param string BuildingName: name of the building you want to build
* \param int CoordX: X coordinate, where you want to build your building
* \param int CoordY: Y coordinate, where you want to build your building
* \param int depth: Current depth or level. Level 1 is depth=1
*
*/
void BuildingManager::CreateBuilding(string BuildingName, int CoordX, int CoordY, int depth, UserInterface ui, SDL_Event event){

	if (BuildingName != "none"){
	
		
		if (CanBuildBuildingHere(CoordX,CoordY) == true){

			Building* bladeTrap = BuildingFactory::create_building(BuildingName);
			id++;
			bladeTrap->set_Id(id);
			bladeTrap->set_level(depth);
			bladeTrap->setTexture(building);
			bladeTrap->setCoords(CoordX, CoordY);
			
			mapdata.buildingDataMap[CoordX][CoordY]=1; 

			buildingList.push_back(bladeTrap);
			camData->mapStruct[camData->currentLevel].entityDataBuildings.building.push_back(buildingList.at(cursor));
			cout << "Rakennus on laitettu\n";

			camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] = camData->mapStruct[camData->currentLevel].entityDataBuildings.building[cursor]->getID();
			Collision(CoordX, CoordY, id);
			cursor++;

			SetBuildingCooldown();
			nextBuilding = ui.eventHandler(event);

		}
		
	}
	if (BuildingName == "spiketrap"){


		if (CanBuildBuildingHere(CoordX, CoordY) == true){

			Building* spiketrap = BuildingFactory::create_building("spiketrap");
			id++;
			spiketrap->set_Id(id);
			spiketrap->set_level(depth);
			spiketrap->setTexture(building);
			spiketrap->setCoords(CoordX, CoordY);

			mapdata.buildingDataMap[CoordX][CoordY] = 1;

			buildingList.push_back(spiketrap);
			camData->mapStruct[camData->currentLevel].entityDataBuildings.building.push_back(buildingList.at(cursor));
			cout << "Rakennus on laitettu\n";

			camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] = camData->mapStruct[camData->currentLevel].entityDataBuildings.building[cursor]->getID();
			Collision(CoordX, CoordY,id);
			cursor++;
			nextBuilding = ui.eventHandler(event);
		}

	}
	if (BuildingName == "woodbarricade"){


		if (CanBuildBuildingHere(CoordX, CoordY) == true){

			Building* woodbarricade = BuildingFactory::create_building("woodbarricade");
			id++;
			woodbarricade->set_Id(id);
			woodbarricade->set_level(depth);
			woodbarricade->setTexture(building);
			woodbarricade->setCoords(CoordX, CoordY);

			mapdata.buildingDataMap[CoordX][CoordY] = 1;

			buildingList.push_back(woodbarricade);
			camData->mapStruct[camData->currentLevel].entityDataBuildings.building.push_back(buildingList.at(cursor));
			cout << "Rakennus on laitettu\n";

			camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] = camData->mapStruct[camData->currentLevel].entityDataBuildings.building[cursor]->getID();
			Collision(CoordX, CoordY, id);
			cursor++;
			nextBuilding = ui.eventHandler(event);
		}

	}
	
	
}

/** \brief Collision: Creates collision to the Building.
*
* \param CoordX: X coordinate, where you want the collision of your building
* \param CoordY: Y coordinate, where you want the collision of your building
*
*/
void BuildingManager::Collision(int CoordX, int CoordY, int id){


	if (camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] == 0 && camData->mapStruct[camData->currentLevel].mapData.mapDim[CoordX][CoordY] != '#'){
		camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] = id;
	}

	/*else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1]>0){
	coord.y = coord.y + 1;
	fightAndKillEnemy(coord);
	coord.y = coord.y - 1;
	}*/
}


/** \brief SetBuildingCooldown: Sets cooldown for a building.
*
* \param string building: name of the building you just build
*
*/
void BuildingManager::SetBuildingCooldown(){
		buildingCooldown = 4;
}
/** \brief GettowerCooldown: Gets building cooldown
*
* \param string building: name of the building which cooldown you want to check
* \return true if cooldown is zero. Return false is cooldown is not yet ended.
*
*/
bool BuildingManager::GetBuildingCooldown(){
	
		if (buildingCooldown > 0){
			return false;
		}
		else{
			return true;
		}

}



/** \brief CanBuildBuildingHere is used when creating a building. It is used to check if you can build your building.
*
* \param int CoordX: X coordinate, where you want to build your building
* \param int CoordY: Y coordinate, where you want to build your building
* \return true if we can build building here. Return false if we can't build building here. 
* 
*/
bool BuildingManager::CanBuildBuildingHere(int CoordX, int CoordY){

	//if playerIsHere is true, then player is in the selected tile.
	bool playerIsHere = false;

	//if buildingInRange is true, then buildingInRange is in allowed range.
	bool buildingInRange = false;

	//if enemyIsHere is true, then enemy is in the selected tile.
	bool enemyIsHere = false;

	//If buildingIsHere is true, then building is already in the selected tile
	bool buildingIsHere = false;

	//If wallIsHere is true, then wall is already in the selected tile
	bool wallIsHere = false;

	//If player is in the selected tile
	if (player->getCoords().x == CoordX && player->getCoords().y == CoordY){
		playerIsHere = true;
	}

	//Range X
	int rangeX = player->getCoords().x - CoordX;
	//Range Y
	int rangeY = player->getCoords().y - CoordY;

	if (rangeX >= -5 && rangeX <= 5 && rangeY >= -5 && rangeY <= 5){
		buildingInRange = true;
	}
	if (camData->mapStruct[camData->currentLevel].entityData.live[CoordX][CoordY] > 0){
		enemyIsHere = true;
	}
	if (mapdata.buildingDataMap[CoordX][CoordY] != 0){
		buildingIsHere = true;
	}
	if (camData->mapStruct[camData->currentLevel].mapData.mapDim[CoordX][CoordY] == '#'){
		wallIsHere = true;
	}
	///Final check. If values are desirable, then we can build a building
	if (playerIsHere == false &&
		buildingInRange == true &&
		buildingIsHere==false &&
		wallIsHere==false && 
		enemyIsHere==false){

		return true;
	}
	//if values are not desirable, then we will not build anything
	else{
		return false;
	}
}

/** \brief initializeBuildings is used when you initialize buildings. Is called only once.
*
* \param _camData: CameraStruct object which BuildingData you want to initialize.
* \param _buildinTexture: Texture object which you want to initialize.
* \param _player: Player object is pass to BuildinManager because we need to use it's coordinates
*
*/
void BuildingManager::initializeBuildings(CameraStruct* _camData, Texture* _buildinTexture, Player* _player){
	//Current X entityDataBuildings coordinate
	int y = 0,
	//Current Y entityDataBuildings coordinate
	x = 0,
	// Current level. Level 1 is depth=0
	depth = 0;
	//Initialize id
	id = 0;
	

	camData = _camData;
	//initialize buildingData object
	buildData = &camData->buildData;
	//building = GetBuilding();
	player = _player;
	//Set textures
	building = _buildinTexture;

	while (depth <= 2){

		while (y<GRID_HEIGHT){//initialises entityData to 0
			if (x<GRID_WIDTH){

				camData->mapStruct[depth].entityDataBuildings.live[x][y] = 0;
				camData->mapStruct[depth].entityDataBuildings.dead[x][y] = 0;
				x++;
			}
			if (x == GRID_WIDTH){
				y++;
				x = 0;
			}
		}	
		depth++;
	}


}




/** \brief This method is
*
* \param depth: Current level. Level 1 is depth=1.
* \return returns the deque that contains Enemy objects.
*
*/
deque<string> BuildingManager::getBuildingListForGeneration(int depth){

	deque<string> buildings;
	if (depth == 1){
		buildings.push_back("bladetrap");
	}
	else if (depth == 2){
		/*characters.push_back("goblin");
		characters.push_back("orc");*/
	}
	else if (depth == 3){
		/*characters.push_back("werewolf");
		characters.push_back("orc");
		characters.push_back("werewolf boss");*/
	}
	return buildings;
}

BuildingManager::~BuildingManager(){
	
}



