#pragma once
#include "Building.h"
#include "LocationCoordinate.h"
class SpikeTrap :public Building
{
public:
	SpikeTrap(void);
	void set_stats(int healths, int strengths, int damage, int accuracy, int luck, int attackCooldowns);

	int Health(void);
	bool Health(int);

	int getID();
	void set_Id(int _id);

	int GetCooldown();

	void setCoords(int, int);
	LocationCoordinates getCoords();

	int Strength();
	int Accuracy();
	int Damage();
	int Luck();

	void set_level(int level);
	int get_level();


	~SpikeTrap();
};