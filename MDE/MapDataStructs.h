#ifndef MAPSDATATRUCTS_H
#define MAPSDATATRUCTS_H

#include "Item.h"
#include "Building.h"
#include <deque>
#include "GlobalDef.h"
#include "enemy.h"

/** \brief contains the 2 dimensional data of the map, which has the floor and walls as its data set 
 *
 */     

struct MapData{
	///the map data set
	char mapDim[GRID_WIDTH][GRID_HEIGHT];

	//Buildings that are found on the floor
	Building* buildingDataMap[GRID_WIDTH][GRID_HEIGHT];
};
/** \brief Contains the data of where the life and the dead entities are for rendering purposes
 *
 */     

struct EntityData{
	///the 2D map of all the alive entities
	int live[GRID_WIDTH][GRID_HEIGHT];
	///the 2D map of all the dead entities
	int dead[GRID_WIDTH][GRID_HEIGHT];
	/// enemy deque
	deque<Enemy*> enemy;
};

/** \brief contains the data of all the items on the map
 *
 */     


struct ItemData{
	///items that are found on the floor
	deque <Item> itemDataMap[GRID_WIDTH][GRID_HEIGHT];

};

#endif // MAPSDATATRUCTS_H
