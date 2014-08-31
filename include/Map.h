#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "GlobalDef.h"
#include <SDL2/SDL.h>
#include <deque>
#include "RNG.h"
#include "MapDataStructs.h"
using namespace std;

/** \brief generates a map and returns it with the getters
 */     


class Map{
	/** \brief the struct used to help in the creation process of the map
	 *
	 */  
	struct RoomDimension{
		///the X coord
		int locx;
		///the y coord
		int locy;
		///the x dimension
		int roomx;
		///the y dimension
		int roomy;
		/// the middle of the x dimension
		int midx;
		///the middle of the y dimension
		int midy;
	};
	
	MapData map;
	int stairs_up[2];
	int stairs_down[2];
public:
	Map(int depth);
	MapData getMap ();
	int * get_stairs_up();
	int * get_stairs_down();
	~Map();
};
#endif
