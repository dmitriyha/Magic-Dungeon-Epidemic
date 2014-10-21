#pragma once
#include "Manager.h"
#include "player.h"
#include "GlobalDef.h"
#include "PlaceItemsAndEnemies.h"
#include "Map.h"
#include "EnemyGen.h"
#include <string>
using namespace std;

class PlayerManager : public Manager
{
	Player *player;
	bool inventory = false;
	int inventory_cursor = 1;
	int max_achieved_depth = 0;
	int kills = 0;
	
public:
	bool playerMoved = false;

	PlayerManager();

	void render();
	int* getPlayerCoord();
	void eventHandler(SDL_Event event);

	void setPlayerPointer(Player* _player);
	int move(int direction);
	void checkTileForItems();
	void rangedCombat(int x, int y);
	string getMainWeaponType();
	int get_inventory_size();
	int dropItem(int inventory_cursor);
	int equipItem(int inventory_cursor);
	int remove_secondary_weapon(int inventory_cursor);
	void inventoryData();
	bool check_player_death();
	//void generateMap();
	Player* getPlayer();
	~PlayerManager();
private:
	void fightAndKillEnemy(int* coord);
};

