#ifndef PLACEITEMSANDENEMIES_H
#define PLACEITEMSANDENEMIES_H

#include"RNG.h"
#include<deque>
#include "GlobalDef.h"
#include "RNG.h"
#include <deque>
#include "Item.h"
#include "Enemy.h"
#include <iostream>
#include "MapDataStructs.h"
using namespace std;

/** \brief places items and enemies on to the map
 *
 */     


class PlaceItemsAndEnemies{
	ItemData itemLayer;
	EntityData entityData;
	deque<Enemy> enemy;
public:
	PlaceItemsAndEnemies(MapData map, deque<Enemy> baddies, int level);
	deque<Enemy> getEnemyList();
	EntityData getLiveEnemies();
	ItemData getItems();
	~PlaceItemsAndEnemies();
};

#endif
