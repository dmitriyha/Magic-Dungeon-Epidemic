#include "BuildingManager.h"


BuildingManager::BuildingManager()
{
	
}

void BuildingManager::render(){
	for (int i = 0; buildingList.size() > i; i++){
		buildingList.at(i)->render();

	}
}

//Creates a Building.
//BuildingName description: name of the building you want to build
//CoordX description: X coordinate, where you want to build your building
//CoordY description: Y coordinate, where you want to build your building
//level description: level where you want yor building build
void BuildingManager::CreateBuilding(string BuildingName, int CoordX, int CoordY, int depth){

	if (BuildingName == "stonetower"){
	
		
		if (CanBuildBuildingHere(CoordX,CoordY) == true){

			Building* tower = BuildingFactory::create_building("stonetower");
			id++;
			tower->set_Id(id);
			tower->set_level(1);
			tower->setTexture(stonetower);
			tower->setCoords(CoordX, CoordY);
			
			mapdata.buildingDataMap[CoordX][CoordY]=1; 

			buildingList.push_back(tower);
			camData->mapStruct[camData->currentLevel].entityDataBuildings.building.push_back(buildingList.at(cursor));
			buildingBuilt = true;
			cout << "Rakennus on laitettu\n";

			camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] = camData->mapStruct[camData->currentLevel].entityDataBuildings.building[cursor]->getID();
			Collision(CoordX, CoordY);
			cursor++;

		}
		
	}
	
	
}

//Creates collision to the Building.
//CoordX description: X coordinate, where you want the collision of your building
//CoordY description: Y coordinate, where you want the collision of your building
void BuildingManager::Collision(int CoordX, int CoordY){


	if (camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] == 0 && camData->mapStruct[camData->currentLevel].mapData.mapDim[CoordX][CoordY] != '#'){
		camData->mapStruct[camData->currentLevel].entityDataBuildings.live[CoordX][CoordY] = 1;
	}

	/*else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y + 1]>0){
	coord.y = coord.y + 1;
	fightAndKillEnemy(coord);
	coord.y = coord.y - 1;
	}*/
}


int BuildingManager::GetId(){
	return id;
}

//CanBuildBuildingHere is used when creating a building. It is used to check if you can build your building.
//CoordX description: X coordinate, where you want to build your building
//CoordY description: Y coordinate, where you want to build your building
bool BuildingManager::CanBuildBuildingHere(int CoordX, int CoordY){

	//if playerIsHere is true, then player is in the selected tile.
	bool playerIsHere = false;

	//if buildingInRange is true, then buildingInRange is in allowed range.
	bool buildingInRange = false;

	//if enemyIsHere is true, then enemy is in the selected tile.
	bool enemyIsHere = false;

	bool buildingIsHere = false;

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


bool BuildingManager::FirstBuildingBuilt(){
	return buildingBuilt;
}

//initializeBuildings is used when you initialize buildings. Is called only once. 
//_camData description: CameraStruct object which BuildingData you want to initialize.
//_buildinTexture  description: Texture object which you want to initialize.
//_player  description: Player object is pass to BuildinManager because we need to use it's coordinates
void BuildingManager::initializeBuildings(CameraStruct* _camData, Texture* _buildinTexture, Player* _player){
	int y = 0, x = 0, depth = 0;
	id = 0;
	buildingBuilt = false;
	camData = _camData;
	//initialize buildingData object
	buildData = &camData->buildData;
	//building = GetBuilding();
	//setBuilding(building);
	player = _player;
	//Set textures
	stonetower = _buildinTexture;
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


Building*  BuildingManager::GetBuilding(){

	return buildData->building;

}

void BuildingManager::setBuilding(Building* _building){
	//building = _building;
}


/** \brief This method is
*
* \param enemies The amount enemies to be generated.
* \param depth the depth of the dungeon used to tweak the difficulty of the level
* \return returns the deque that contains Enemy objects.
*
*/

deque<string> BuildingManager::getBuildingListForGeneration(int depth){
	deque<string> buildings;
	if (depth == 1){
		buildings.push_back("stonetower");
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



