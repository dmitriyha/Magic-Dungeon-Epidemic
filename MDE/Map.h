#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "GlobalDef.h"
#include <SDL.h>
#include <deque>
#include "RNG.h"
#include "MapDataStructs.h"
#include "CameraStruct.h"
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
	SDL_Renderer* renderer;
	Texture* tex;

	CameraStruct* mapData;
	
	LocationCoordinates stairs_down;
	LocationCoordinates stairs_up;
	LocationCoordinates stairs_up2;
public:

	Map(CameraStruct* cam);
	Texture* getMapAsTexture();
	void render();
	void setRenderer(SDL_Renderer* _renderer);
	LocationCoordinates GetStairsUpCoord();
	
	~Map();
};
#endif
