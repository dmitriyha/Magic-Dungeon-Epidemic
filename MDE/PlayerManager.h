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
	int max_achieved_depth = 0;
	int kills = 0;
public:
	PlayerManager();
	void setPlayerPointer(Player* _player);
	int move(int direction);
	void setPlayer(Player* player);
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

