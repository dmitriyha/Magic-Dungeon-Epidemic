#pragma once
#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "Controls.h"
#include "camera.h"
#include "buildingManager.h"
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
	BuildingManager* managebuilding = new BuildingManager();

	Window win ;
	//Controls controls;
	bool quit = false;

	
public:
	

	Game();
	void run();
	~Game();
};

