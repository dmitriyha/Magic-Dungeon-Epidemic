#ifndef PLACEITEMSANDENEMIES_H
#define PLACEITEMSANDENEMIES_H

#include"RNG.h"
#include<deque>
#include "GlobalDef.h"
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

	CameraStruct* enemyData;

	
public:
	PlaceItemsAndEnemies(CameraStruct* cam,Texture* texture);
	~PlaceItemsAndEnemies();
};

#endif
