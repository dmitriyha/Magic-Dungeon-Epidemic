#pragma once

#include <iostream>
#include "Texture.h"
#include "LocationCoordinate.h"
//#include "BuildingManager.h"


using namespace std;

/** \brief The Enemy entity, that contains all of the data relevant to it
*
*/


class Building{
public:
	//BuildingManager* buildManager;

protected:
	Texture* texture;

	///the level of the Enemy
	int level;
	//
	int health;

	int strength;
	int damage;
	int accuracy;
	int luck;
	int id;

	
	LocationCoordinates coord;
	SDL_Rect charSprite;

public:
	Building();
	
	virtual void set_level(int level);
	virtual int get_level();
	virtual ~Building();


	virtual void set_stats(int healths, int strengths, int damage, int accuracy, int lucks);

	virtual int Health(void);
	virtual bool Health(int);
	virtual void set_Id(int _id);

	void render();
	void setTexture(Texture* _texture);



	virtual int getID();

	virtual void setCoords(int, int);
	virtual LocationCoordinates getCoords();

	virtual int Strength();
	virtual int Accuracy();
	virtual int Luck();
	virtual int Damage();

};

