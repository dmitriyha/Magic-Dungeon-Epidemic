#ifndef AI_H
#define AI_H
#include <iostream>
#include "GlobalDef.h"
#include"RNG.h"
#include "MapDataStructs.h"
using namespace std;

/** \brief The class that decides which way the enemies move 
 *
 */     


class ArtificialIntelligence{
	RNG rand;
public:
	ArtificialIntelligence();
	int direction(int* PlayerLoc,int* coord,EntityData liveEntities,MapData maplayer);
	~ArtificialIntelligence();
};

#endif
