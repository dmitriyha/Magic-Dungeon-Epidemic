#pragma once
#include "Building.h"
#include "BuildingFactory.h"
#include "Manager.h"
#include "BuildingStruct.h"
#include "Window.h"
#include <vector>
#include "CameraStruct.h"

using namespace std;

class BuildingManager : public Manager
{


public:
	Texture* stonetower;
	Window win;
	BuildingData *buildData;
	MapData mapdata;
	CameraStruct* camData;
	Building* building;

	BuildingManager();
	
	void CreateBuilding(string BuildingName, int CoordX, int CoordY, int level);
	void initializeBuildings(CameraStruct* camData);
	Building* GetBuilding();
	void setBuilding(Building* _building);
	void render();
	bool FirstBuildingBuilt();
	vector<string> getBuildingListForGeneration(int depth);
	void free();
	
	~BuildingManager();
private:
	bool buildingBuilt;
};



