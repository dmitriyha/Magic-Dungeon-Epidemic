#pragma once
#include <iostream>
#include "SDL.h"
#include "Window.h"
#include "Controls.h"
#include "buildingManager.h"
#include <string>
#include "ItemRenderer.h"
#include "LocationCoordinate.h"
#include "MouseCoordinates.h"
#include "PlaceItemsAndEnemies.h"
#include "AttackCooldownStruct.h"
#include "MapDataStructs.h"

using namespace std;
class Game
{
	SDL_Event event;
	MapData mapdata;
	CameraStruct* camData=new CameraStruct;
	AttackCooldownStruct* attackCooldownStruct = new AttackCooldownStruct;
	Map *map;
	Texture* mapTexture;
	PlayerManager managePlayer;
	EnemyManager manageEnemy;
	BuildingManager managebuilding;
	ItemRenderer renderItem;
	Window win ;
	UserInterface ui;

	string nextBuilding = "none";

	//Controls controls;
	bool quit = false;
public:
	Game();
	void run();
	~Game();
private:
	int mouseCoordX;
	int mouseCoordY;
	void initialize();
	int turn;
	bool CheckTile(int x, int y, CameraStruct* dataForManaging);
	int towerCooldown;
	bool Bresenham(int x1, int y1, int const x2, int const y2, CameraStruct* dataForManaging);
	int trapCooldown;
	void TrapAttackCooldownCheck(AttackCooldownStruct* attackCooldownStruct);
	void debugPrintAttackCooldowns(AttackCooldownStruct* attackCooldownStruct);
};
