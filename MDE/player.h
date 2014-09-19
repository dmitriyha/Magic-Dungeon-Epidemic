#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <iostream>
#include "Inventory.h"
#include "Battle.h"
using namespace std;


/** \brief stores all what only the player requires
 */     


class Player : public Character{
protected:
	Inventory* inventory=new Inventory();
	int xp=0;
	int level=1;
	int next_level=400;
	int lvl_points=0;
public:
	int fight(Character * character);

	Inventory* getInventory();

	void set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks, int ID);

	int Health(void);
	bool Health(int);

	int getID();

	void setCoords(int, int);
	int* getCoords();

	int Strength();
	int Dexterity();
	int Wits();
	int Sanity();
	int Stamina();
	int Charisma();
	int Awareness();
	int Luck();

	void setPrimaryWeapon(Item item);

	void set_xp(int creature_level);
	int get_level_progress();
	int get_level();
	~Player();
};

#endif
