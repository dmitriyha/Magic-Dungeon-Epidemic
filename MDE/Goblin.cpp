#include "Goblin.h"


Goblin::Goblin(){
	charSprite = { 0, 0, 40, 57 };
	charSpriteDead = { 188, 270, 50, 50 };
}


void Goblin::setPrimaryWeapon(Item* item){
	weapon = item;
}

/** \brief sets the stats of the  Goblin entity
*
* \param healths max health
* \param strengths the initial strength
* \param dexteritys the initialdexterity
* \param witss the initial wits
* \param sanitys the initial sanity
* \param staminas the initial stamina
* \param charismas the initialcharisma
* \param awarenesss the initial awareness
* \param lucks the initial luck
* \param ID the ID of this entity
*
*/
void  Goblin::set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks, int ID){
	health = healths;
	strength = strengths;
	dexterity = dexteritys;
	wits = witss;
	sanity = sanitys;
	stamina = staminas;
	charisma = charismas;
	awareness = awarenesss;
	luck = lucks;
	id = ID;
}

/** \brief the getter of health
*
* \return the current health
*
*/


int  Goblin::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/

bool  Goblin::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the  Goblin antity
*
* \return the ID of the entity
*
*/


int  Goblin::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  Goblin::setCoords(int x, int y){
	coord = { x, y };
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/



LocationCoordinates   Goblin::getCoords(){
	return coord;
}





/** \brief Strength getter
*
* \return strength attribute
*
*/
int  Goblin::Strength(){
	return strength;
}

/** \brief dexterity getter
*
* \return dexterity attribute
*
*/


int  Goblin::Dexterity(){
	return dexterity;
}

/** \brief Wits getter
*
* \return Wits attribute
*
*/

int  Goblin::Wits(){
	return wits;
}

/** \brief Sanity getter
*
* \return Sanity attribute
*
*/

int  Goblin::Sanity(){
	return sanity;
}

/** \brief Stamina getter
*
* \return Stamina attribute
*
*/

int  Goblin::Stamina(){
	return stamina;
}

/** \brief Charisma getter
*
* \return Charisma attribute
*
*/

int  Goblin::Charisma(){
	return charisma;
}

/** \brief Awareness getter
*
* \return Awareness attribute
*
*/

int  Goblin::Awareness(){
	return awareness;
}

/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  Goblin::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void Goblin::set_level(int lvl){
	level = lvl;
}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int Goblin::get_level(){
	return level;
}


Goblin::~Goblin()
{
}
