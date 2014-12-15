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
using namespace std;
class Game
{
	SDL_Event event;
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
	void initialize();
	int turn;
	int towerCooldown;
	int trapCooldown;
	void TrapAttackCooldownCheck(AttackCooldownStruct* attackCooldownStruct);
	void debugPrintAttackCooldowns(AttackCooldownStruct* attackCooldownStruct);
};
