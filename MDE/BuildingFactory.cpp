#include "BuildingFactory.h"


/** \brief Create a building factory 
*
* \param string buildingType. buildingType is a type of building you want to build. 
* \return If buildingType matches available buildings, it returns building entity you want to build.
*
*/
Building* BuildingFactory::create_building(string buildingType){

	if (buildingType == "bladetrap"){
		BladeTrap* bladetrap = new BladeTrap();
		bladetrap->set_stats(4, 1, 1, 1, 1);
		bladetrap->setType(BLADETRAP);
		return bladetrap;
	}
	if (buildingType == "spiketrap"){
		SpikeTrap* spiketrap = new SpikeTrap();
		spiketrap->set_stats(1, 1, 1, 1, 1,4);
		spiketrap->setType(TRAP);
		return spiketrap;
	}
	if (buildingType == "woodbarricade"){
		WoodBarricade* woodbarricade = new WoodBarricade();
		woodbarricade->set_stats(4, 1, 1, 1, 1, 4);
		woodbarricade->setType(BARRICADE);
		return woodbarricade;
	}

}