#ifndef CONTROLS_H
#define CONTROLS_H

#include <iostream>
#include <SDL2/SDL.h>
#include "ActorManager.h"
#include "CameraStruct.h"
using namespace std;

class Controls{
	///show inventory or not
	bool inventory=false;
	///the inventory cursor location tracker
	int inventory_cursor=1;
	///first run flag
	bool first_run=true;
	///the logic of the game
	ActorManager *manage;
	///the camera data to be handled in Camera
	CameraStruct* cameraData;
public:
	Controls();
	void buttons(SDL_Event event);
	CameraStruct* getData();
	~Controls();
};

#endif
