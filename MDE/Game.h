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

	Map *map;
	Texture* mapTexture;
	PlayerManager managePlayer;
	EnemyManager manageEnemy;

	Window win ;
	//Controls controls;
	bool quit = false;

	
public:
	

	Game();
	void run();
	~Game();
};

