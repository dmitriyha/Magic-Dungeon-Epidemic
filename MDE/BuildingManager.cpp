#include "BuildingManager.h"


BuildingManager::BuildingManager()
{
	
}

void BuildingManager::render(){
	building->render();
}

//Creates a Building.
//BuildingName description: name of the building you want to build
//CoordX description: X coordinate, where you want to build your building
//CoordY description: Y coordinate, where you want to build your building
//level description: level where you want yor building build
void BuildingManager::CreateBuilding(string BuildingName, int CoordX, int CoordY, int depth){
	
	if (BuildingName == "stonetower"){

	/*	buildData->building = BuildingFactory::create_building("stonetower");

		if (depth == 1){
			buildData->building->set_stats(1, 1, 1, 1, 1, 1);
			buildData->building->set_level(depth);
		}
		if (depth == 2){
			buildData->building->set_stats(2, 2, 2, 2, 2, 2);
			buildData->building->set_level(depth);
		}
		
		buildData->building->setTexture(stonetower);
		buildData->building->setCoords(CoordX, CoordY);
		mapdata.buildingDataMap[CoordX][CoordY] = buildData->building;
		buildingBuilt = true;*/

		Building* tower = BuildingFactory::create_building("stonetower");
		tower->set_stats(1, 1, 1, 1, 1, 1);
		tower->set_level(1);
		tower->setTexture(stonetower);
		tower->setCoords(CoordX, CoordY);
		mapdata.buildingDataMap[CoordX][CoordY] = tower; 
		buildingBuilt = true;
	}
	
}
bool BuildingManager::FirstBuildingBuilt(){
	return buildingBuilt;
}


void BuildingManager::initializeBuildings(CameraStruct* camData){
	buildingBuilt = false;
	
	//initialize buildingData object
	buildData = &camData->buildData;
	building = GetBuilding();
	setBuilding(building);
	
	//Set textures
	stonetower = new Texture();
	stonetower->setRenderer(win.getRenderer());
	stonetower->makeTexture("img\\TowerStone.png");


}


Building*  BuildingManager::GetBuilding(){

	return buildData->building;

}

void BuildingManager::setBuilding(Building* _building){
	building = _building;
}


/** \brief This method is
*
* \param enemies The amount enemies to be generated.
* \param depth the depth of the dungeon used to tweak the difficulty of the level
* \return returns the deque that contains Enemy objects.
*
*/

vector<string> BuildingManager::getBuildingListForGeneration(int depth){
	vector<string> buildings;
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



