#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Item.h"
#include "Texture.h"
#include "Building.h"
#include "LocationCoordinate.h"
using namespace std;

/** \brief the base class of Player and Enemy
 */     


class Character{
protected:
	Texture* texture;

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
	SDL_Rect charSprite;
	SDL_Rect charSpriteDead;

public: 

	
	virtual int fight(Character* character);
//	virtual int fight(Building* building);

	void setTexture(Texture* _texture);
	void render();

	virtual void set_stats(int healths,int strengths,int dexteritys,int witss,int sanitys,int staminas,int charismas,int awarenesss,int lucks,int ID);
	
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
	
	virtual ~Character();
};
#endif
