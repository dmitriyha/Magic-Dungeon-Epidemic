#pragma once
#include "enemy.h"
class Goblin :public Enemy
{
public:
	Goblin(void);
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

	void setPrimaryWeapon(Item* item);

	void set_level(int level);
	int get_level();

	~Goblin();
};

