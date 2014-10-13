#include "BuildingFactory.h"


/** \brief Create a building factory 
*
* \param string buildingType. buildingType is a type of building you want to build. 
*
* \return If buildingType matches available buildings, it returns building entity you want to build.
*
*/
Building* BuildingFactory::create_building(string buildingType){

	if (buildingType == "stonetower"){
		return new StoneTower();
	}

}