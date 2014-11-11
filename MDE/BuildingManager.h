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
#include "PlaceItemsAndEnemies.h"

using namespace std;

class BuildingManager : public Manager
{


public:
	Texture* stonetower;
	BuildingData *buildData;
	MapData mapdata;
	CameraStruct* camData;
	deque<Building*> buildingList;
	Player* player;
	int cursor;




	BuildingManager();
	bool CanBuildBuildingHere(int CoordX, int CoordY);
	void CreateBuilding(string BuildingName, int CoordX, int CoordY, int level);
	void initializeBuildings(CameraStruct* camData, Texture* _buildinTexture, Player* _player);
	void initializeBuildings(Texture* _buildinTexture);
	void render();
	void SetBuildingCooldown(string building);
	bool GetBuildingCooldown(string building);
	deque<string> getBuildingListForGeneration(int depth);
	void free();
	void Collision(int CoordX, int CoordY);
	int stoneTowerCooldown;
	~BuildingManager();
private:
	int id;
	
};



