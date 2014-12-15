#pragma once
#include <iostream>
#include "Building.h"
#include "StoneTower.h"
#include "SpikeTrap.h"
#include "WoodBarricade.h"

using namespace std;

class BuildingFactory
{
public:
	static Building* create_building(string buildingType);
};