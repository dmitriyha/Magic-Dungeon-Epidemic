#pragma once
#include "Building.h"
#include "LocationCoordinate.h"
class BladeTrap :public Building
{
public:
	BladeTrap(void);
	void set_stats(int healths, int strengths,int damage, int accuracy,int luck);

	int Health(void);
	bool Health(int);

	int getID();
	void set_Id(int _id);

	void setCoords(int, int);
	LocationCoordinates getCoords();

	int Strength();
	int Accuracy();
	int Damage();
	int Luck();

	void set_level(int level);
	int get_level();
	

	~BladeTrap();
};