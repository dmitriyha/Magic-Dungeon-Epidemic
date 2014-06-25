#ifndef MAPSDATATRUCTS_H
#define MAPSDATATRUCTS_H

#include "Item.h"
#include <deque>

struct MapData{
	char mapDim[GRID_WIDTH][GRID_HEIGHT];
	
};

struct EntityData{
	int live[GRID_WIDTH][GRID_HEIGHT];
	int dead[GRID_WIDTH][GRID_HEIGHT];
};

struct ItemData{
	deque <Item> itemDataMap[GRID_WIDTH][GRID_HEIGHT];
};

#endif // MAPSDATATRUCTS_H
