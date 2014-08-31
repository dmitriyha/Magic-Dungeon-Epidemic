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
	///this is the struct that tracks the alive and dead entities
	EntityData entityData[10];
	///where the map data is stored
	MapData mapLayer[10];
	///the struct where items on the map are stored
	ItemData itemLayer[10];
	///the stairs that lead to an upper level of the dungeon
	int stairs_up[10][2];
	///the stairs that lead to an lower level of the dungeon
	int stairs_down[10][2];
	///the Player Object
	Player *player=new Player();
	///deque  that contains Enemy objects
	deque<Enemy> enemy[10];
	///the place where we will render
	SDL_Renderer *screen;
	///The object which decides how the enemies move
	ArtificialIntelligence *npc=new ArtificialIntelligence();
	///Inventory object
	Inventory * inv = new Inventory();
	/// Randomness generator
	RNG random;
	///the battle phase
	Battle battle;
	///current depth the player is on
	int dungeon_depth = 0;
	/// the deepest the player has been
	int max_achieved_depth = 0;
	///sound object
	sound_play * play = new sound_play ("music\\hit.wav");
	
	///kills
	int kills = 0;
	
	///the current level map data
	MapStruct mapTosend;
	///the inventory
	InventoryStruct inventoryToSend;
	///The user Interface where you can see the players stats
	UserInterfaceStruct UIDataToSend;
	
	///The final data struct that will be sent to be processed by the camera class
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
