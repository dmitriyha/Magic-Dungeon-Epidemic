#ifndef CONTROLS_H
#define CONTROLS_H

#include <iostream>
#include <SDL2/SDL.h>
#include "ActorManager.h"
#include "CameraStruct.h"
using namespace std;

class Controls{
	bool inventory=false;
	int inventory_cursor=1;
	bool first_run=true;
	SDL_Surface * Screen;
	ActorManager *manage;
	CameraStruct* cameraData;
public:
	Controls();
	void buttons(SDL_Event event);
	CameraStruct* getData();
	~Controls();
};

#endif
