#ifndef PLACEITEMSANDENEMIES_H
#define PLACEITEMSANDENEMIES_H

#include"RNG.h"
#include "LocationCoordinate.h"
#include<deque>
#include "GlobalDef.h"
#include "Map.h"
#include "RNG.h"
#include <deque>
#include "Item.h"
#include "enemy.h"
#include <iostream>
#include "CameraStruct.h"
#include "MapDataStructs.h"
using namespace std;

/** \brief places items and enemies on to the map
 *
 */     


class PlaceItemsAndEnemies{

	CameraStruct* entityData;

public:
	PlaceItemsAndEnemies(CameraStruct* cam,Texture* texture, Map* map);
	LocationCoordinates PlaceBossesToTheMapCheck(CameraStruct* cam, Map* map, LocationCoordinates upstairs);
	void PlaceBossesToTheMap(CameraStruct* cam, Texture* texture, Map* map,int cursor);
	~PlaceItemsAndEnemies();
};

#endif
