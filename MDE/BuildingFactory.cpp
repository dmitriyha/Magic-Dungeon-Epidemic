#include "BuildingFactory.h"


/** \brief Create a building factory 
*
* \param string buildingType. buildingType is a type of building you want to build. 
* \return If buildingType matches available buildings, it returns building entity you want to build.
*
*/
Building* BuildingFactory::create_building(string buildingType){



	if (buildingType == "stonetower"){
		StoneTower* stonetower = new StoneTower();
		stonetower->set_stats(1, 1, 1, 1, 1);
		return stonetower;
	}

}