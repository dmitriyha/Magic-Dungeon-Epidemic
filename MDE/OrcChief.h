#pragma once
#include "enemy.h"
class OrcChief :public Enemy
{
public:
	OrcChief(void);
	void set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks, string names, string types);

	string GetName();
	string GetType();

	int Health(void);
	bool Health(int);

	int getID();
	void set_Id(int _id);

	void setCoords(int, int);
	LocationCoordinates  getCoords();

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

	~OrcChief();
};

