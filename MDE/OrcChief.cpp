#include "OrcChief.h"


OrcChief::OrcChief(){

	Enemy::Enemy();

	charSpriteDead = { 188, 270, 50, 50 };
}


void OrcChief::setPrimaryWeapon(Item* item){
	weapon = item;
}

/** \brief sets the stats of the  OrcChief entity
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
void  OrcChief::set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks){
	health = healths;
	strength = strengths;
	dexterity = dexteritys;
	wits = witss;
	sanity = sanitys;
	stamina = staminas;
	charisma = charismas;
	awareness = awarenesss;
	luck = lucks;
}

/** \brief the getter of health
*
* \return the current health
*
*/


int  OrcChief::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/

bool  OrcChief::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the  OrcChief antity
*
* \return the ID of the entity
*
*/


int  OrcChief::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  OrcChief::setCoords(int x, int y){
	coord = { x, y };
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/



LocationCoordinates   OrcChief::getCoords(){
	return coord;
}

//Sets id
void OrcChief::set_Id(int _id){
	id = _id;
}


/** \brief Strength getter
*
* \return strength attribute
*
*/
int  OrcChief::Strength(){
	return strength;
}

/** \brief dexterity getter
*
* \return dexterity attribute
*
*/


int  OrcChief::Dexterity(){
	return dexterity;
}

/** \brief Wits getter
*
* \return Wits attribute
*
*/

int  OrcChief::Wits(){
	return wits;
}

/** \brief Sanity getter
*
* \return Sanity attribute
*
*/

int  OrcChief::Sanity(){
	return sanity;
}

/** \brief Stamina getter
*
* \return Stamina attribute
*
*/

int  OrcChief::Stamina(){
	return stamina;
}

/** \brief Charisma getter
*
* \return Charisma attribute
*
*/

int  OrcChief::Charisma(){
	return charisma;
}

/** \brief Awareness getter
*
* \return Awareness attribute
*
*/

int  OrcChief::Awareness(){
	return awareness;
}

/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  OrcChief::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void OrcChief::set_level(int lvl){
	level = lvl;



}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int OrcChief::get_level(){
	return level;
}


OrcChief::~OrcChief()
{
}
