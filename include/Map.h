#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "GlobalDef.h"
#include <SDL2/SDL.h>
#include <deque>
#include "RNG.h"
#include "MapDataStructs.h"
using namespace std;

struct RoomDimension{
	int locx;
	int locy;
	int roomx;
	int roomy;
	int midx;
	int midy;
};

class Map{
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
