#pragma once
#include "Building.h"
#include "BuildingFactory.h"
#include "Manager.h"
#include "BuildingStruct.h"
#include "Window.h"
#include <vector>
#include <deque>
#include "CameraStruct.h"
#include "Texture.h"
#include "UserInterface.h"
#include "PlaceItemsAndEnemies.h"
#include "MouseCoordinates.h"

using namespace std;

class BuildingManager : public Manager
{


public:
	Texture* building;
	BuildingData *buildData;
	MapData mapdata;
	CameraStruct* camData;
	deque<Building*> buildingList;
	Player* player;
	int cursor;




	BuildingManager();
	bool CanBuildBuildingHere(int CoordX, int CoordY);
	bool CreateBuilding(string BuildingName, MouseCoordinates coord, int level, SDL_Event event);
	void initializeBuildings(CameraStruct* camData, Texture* _buildinTexture, Player* _player);
	void initializeBuildings(Texture* _buildinTexture);
	void render();
	void SetBuildingCooldown();
	bool GetBuildingCooldown();
	deque<string> getBuildingListForGeneration(int depth);
	void free();
	void Collision(int CoordX, int CoordY, int id);
	int buildingCooldown;
	~BuildingManager();
private:
	int id;
	string nextBuilding = "none";
	bool buildingNotPlaced = true;
	
};



