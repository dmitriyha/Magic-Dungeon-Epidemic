#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Item.h"
#include "Texture.h"
#include "Building.h"
#include "LocationCoordinate.h"
#include "Object.h"
using namespace std;

/** \brief the base class of Player and Enemy
 */     


class Character:public Object{
	int direction;
protected:
	string name;
	string type;

	int health;
	int strength;
	int dexterity;
	int wits;
	int sanity;
	int stamina;
	int charisma;
	int awareness;
	int luck;
	int id;

	

	LocationCoordinates coord;

	//Location and size in the sprite sheet
	
	SDL_Rect charSpriteDead;

	SDL_Rect faceUp;
	SDL_Rect faceLeft;
	SDL_Rect faceRight;
	SDL_Rect faceDown;

public: 
	Character();
	
	virtual int fight(Character* character);
//	virtual int fight(Building* building);
	virtual string GetName();
	virtual string GetType();

	void render();

	virtual void set_stats(int healths,int strengths,int dexteritys,int witss,int sanitys,int staminas,int charismas,int awarenesss,int lucks,int ID, string name, string type);
	
	virtual int Health(void);
	virtual bool Health(int);
	
	virtual int getID();
	
	virtual void setCoords(int, int);
	virtual LocationCoordinates  getCoords();
	virtual int Strength();
	virtual int Dexterity();
	virtual int Wits();
	virtual int Sanity();
	virtual int Stamina();
	virtual int Charisma();
	virtual int Awareness();
	virtual int Luck();

	virtual void setPrimaryWeapon(Item item);

	void setDirection(int direction);
	
	virtual ~Character();
};
#endif
