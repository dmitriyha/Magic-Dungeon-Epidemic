#ifndef AI_H
#define AI_H
#include <iostream>
#include "GlobalDef.h"
#include"RNG.h"
#include "MapDataStructs.h"
#include "CameraStruct.h"
using namespace std;

/** \brief The class that decides which way the enemies move 
 *
 */     


class ArtificialIntelligence{
	RNG rand;
	//CameraStruct* dataForManaging;
public:
	ArtificialIntelligence();
	int direction(LocationCoordinates  PlayerLoc, LocationCoordinates coord, EntityData liveEntities, MapData maplayer, CameraStruct* dataForManaging);
	~ArtificialIntelligence();
};

#endif
