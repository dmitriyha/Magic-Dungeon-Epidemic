#include "GoblingKing.h"


GoblingKing::GoblingKing(){

	Enemy::Enemy();

	charSpriteDead = { 188, 270, 50, 50 };
}


void GoblingKing::setPrimaryWeapon(Item* item){
	weapon = item;
}

/** \brief sets the stats of the  GoblingKing entity
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
void  GoblingKing::set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks){
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


int  GoblingKing::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/

bool  GoblingKing::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the  GoblingKing antity
*
* \return the ID of the entity
*
*/


int  GoblingKing::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  GoblingKing::setCoords(int x, int y){
	coord = { x, y };
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/



LocationCoordinates   GoblingKing::getCoords(){
	return coord;
}

//Sets id
void GoblingKing::set_Id(int _id){
	id = _id;
}


/** \brief Strength getter
*
* \return strength attribute
*
*/
int  GoblingKing::Strength(){
	return strength;
}

/** \brief dexterity getter
*
* \return dexterity attribute
*
*/


int  GoblingKing::Dexterity(){
	return dexterity;
}

/** \brief Wits getter
*
* \return Wits attribute
*
*/

int  GoblingKing::Wits(){
	return wits;
}

/** \brief Sanity getter
*
* \return Sanity attribute
*
*/

int  GoblingKing::Sanity(){
	return sanity;
}

/** \brief Stamina getter
*
* \return Stamina attribute
*
*/

int  GoblingKing::Stamina(){
	return stamina;
}

/** \brief Charisma getter
*
* \return Charisma attribute
*
*/

int  GoblingKing::Charisma(){
	return charisma;
}

/** \brief Awareness getter
*
* \return Awareness attribute
*
*/

int  GoblingKing::Awareness(){
	return awareness;
}

/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  GoblingKing::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void GoblingKing::set_level(int lvl){
	level = lvl;



}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int GoblingKing::get_level(){
	return level;
}


GoblingKing::~GoblingKing()
{
}
