#ifndef Build_H
#define Build_H

#include <iostream>
#include "Texture.h"


using namespace std;

/** \brief The Enemy entity, that contains all of the data relevant to it
*
*/


class Building{


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

	int coord[2];
	SDL_Rect charSprite;

public:
	Building();
	
	virtual void set_level(int level);
	virtual int get_level();
	virtual ~Building();


	//virtual int fight(Building * Building);

	virtual void set_stats(int healths, int strengths, int damage, int accuracy, int lucks, int ID);

	virtual int Health(void);
	virtual bool Health(int);

	void render();
	void setTexture(Texture* _texture);

	virtual int getID();

	virtual void setCoords(int, int);
	virtual int* getCoords();

	virtual int Strength();
	virtual int Accuracy();
	virtual int Luck();
	virtual int Damage();

};

#endif