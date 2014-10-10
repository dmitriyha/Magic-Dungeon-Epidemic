#include "BuildingFactory.h"


Building* BuildingFactory::create_building(string buildingType){

	if (buildingType == "stonetower"){
		return new StoneTower();
	}

}