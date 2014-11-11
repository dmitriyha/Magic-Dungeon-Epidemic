#ifndef BUILDSTRUCT_H
#define BUILDSTRUCT_H
#include "player.h"
#include "Building.h"


struct BuildingData{
	Building* building;

};

/** \brief Contains the data of where the life and the dead entities are for rendering purposes
*
*/

struct EntityDataOfBuildings{
	///the 2D map of all the alive entities
	int live[GRID_WIDTH][GRID_HEIGHT];
	///the 2D map of all the dead entities
	int dead[GRID_WIDTH][GRID_HEIGHT];
	/// enemy deque
	deque<Building*> building;
};


#endif // BUILDSTRUCT_H