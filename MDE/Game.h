#pragma once
#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "Controls.h"
#include "camera.h"
#include <string>
using namespace std;


class Game
{
	SDL_Event event;
	CameraStruct* camData=new CameraStruct;

	Texture* mapTexture;

	Window win ;
	//Controls controls;
	bool quit = false;

	Player player;
public:
	

	Game();
	void run();
	~Game();
};

