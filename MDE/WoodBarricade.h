#pragma once
#include "Building.h"
#include "LocationCoordinate.h"
class WoodBarricade :public Building
{
public:
	WoodBarricade(void);
	void set_stats(int healths, int strengths, int damage, int accuracy, int luck, int attackCooldowns);

	int Health(void);
	bool Health(int);

	int getID();
	void set_Id(int _id);

	void setCoords(int, int);
	LocationCoordinates getCoords();

	int Strength();

	void set_level(int level);
	int get_level();


	~WoodBarricade();
};