#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H

#include <iostream>
#include "GlobalDef.h"
#include <deque>
#include "EnemyGen.h"
#include "Battle.h"
#include "ArtificialIntelligence.h"
#include <windows.h>
#include "Map.h"
#include "camera.h"
#include "Item.h"
#include "Inventory.h"
#include "PlaceItemsAndEnemies.h"
#include "player.h"
#include "enemy.h"
#include "sound_play.h"
#include "MapDataStructs.h"
#include "CameraStruct.h"
using namespace std;

class ActorManager{
	EntityData entityData[10];
	MapData mapLayer[10];
	ItemData itemLayer[10];
	int stairs_up[10][2];
	int stairs_down[10][2];
	Player *player=new Player();
	deque<Enemy> enemy[10];
	SDL_Renderer *screen;
	ArtificialIntelligence *npc=new ArtificialIntelligence();
	Inventory * inv = new Inventory();
	RNG random;
	Battle battle;
	int dungeon_depth = 0;
	int max_achieved_depth = 0;
	sound_play * play = new sound_play ("music\\hit.wav");
	
	int kills = 0;
	
	MapStruct mapTosend;
	InventoryStruct inventoryToSend;
	UserInterfaceStruct UIDataToSend;
	
	CameraStruct finalCameraData;
	
	int player_damage;
	int enemy_damage;
public:
	ActorManager();
	int playerMovement(int direction);
	void AI();
	int dropItem(int inventory_cursor);
	int get_inventory_size();
	int equipItem(int cursor_position);
	int remove_secondary_weapon(int cursor_position);
	bool check_player_death();
	CameraStruct* getData();
	~ActorManager();
private:
	void fightAndKillEnemy(int* coords);
	void checkTileForItems();
	void level_generator();
};
#endif
