#pragma once
#include "enemy.h"
class GoblingKing :public Enemy
{
public:
	GoblingKing(void);
	void set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks);

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

	~GoblingKing();
};

