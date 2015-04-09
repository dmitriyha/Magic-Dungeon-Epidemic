#pragma once
#include "Manager.h"
#include "player.h"
#include "GlobalDef.h"
#include "PlaceItemsAndEnemies.h"
#include "Map.h"
#include "EnemyGen.h"
#include "Building.h"
#include "BuildingFactory.h"
#include "BuildingManager.h"
#include <string>
#include "LocationCoordinate.h"
#include "MouseCoordinates.h"
using namespace std;

class PlayerManager : public Manager
{
	Player *player;
	bool inventory = false;
	int inventory_cursor = 1;
	int max_achieved_depth = 0;
	int kills = 0;
	int mouseCoordX, mouseCoordY;
	string nextBuilding = "none";
	BuildingData *buildData;
	
public:
	bool playerMoved = false;
	int rangedCombatCooldown;
	PlayerManager();

	void render();
	BuildingManager PlayerActionManager(SDL_Event event, CameraStruct* camData, MapData mapdata, BuildingManager managebuilding, UserInterface ui);
	LocationCoordinates  getPlayerCoord();
	void eventHandler(SDL_Event event, int& turn);
	MouseCoordinates mouseEventHandler(SDL_Event event);
	void setPlayerPointer(Player* _player);
	int move(int direction);
	void RangedCombatAttackCooldownCheck();
	void checkTileForItems();
	void rangedCombat(int coordX, int coordY, CameraStruct* dataForManaging);
	string getMainWeaponType();
	int get_inventory_size();
	int dropItem(int inventory_cursor);
	void RangedCombatAttackCooldownCheck(AttackCooldownStruct* attackCooldownStruct);
	int equipItem(int inventory_cursor);
	void SetRangedCombatCooldown(int cooldown);
	bool GetRangedCombatCooldown();
	bool CheckIfThereIsObstaclesInRangedCombat(int x1, int y1, int const x2, int const y2, CameraStruct* dataForManaging);
	bool InRangeOfRangedWeaponCheck(int destinationX, int destinationY, int range, CameraStruct* camData, MapData mapdata);
	bool CheckTile(int x, int y, CameraStruct* dataForManaging);
	bool Bresenham(int x1, int y1, int const x2, int const y2, CameraStruct* dataForManaging);
	int remove_secondary_weapon(int inventory_cursor);
	void inventoryData();
	void RemoveArrows(int remove);
	int Arrows();
	void AddArrows(int newArrows);
	bool check_player_death();
	int IfThereIsBuilding(CameraStruct* dataForManaging, int currentdepth, int xCoord, int yCoord);
	
	//void generateMap();
	Player* getPlayer();
	~PlayerManager();
private:
	void fightAndKillEnemy(LocationCoordinates coord);
};

